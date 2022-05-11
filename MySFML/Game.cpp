#include "Game.h"

Game::Game() {
	std::cout << "CRINGE, get outa da default constructer bozo" << std::endl;
}

Game::Game(sf::RenderWindow& iwindow) {
	window = &iwindow;
	score = 0;
	enemyCount = 2000;
	eCounter = 1;
	this->enemyWeight[0] = 4;
	this->enemyWeight[1] = 4;
	this->enemyWeight[2] = 1;
	canShoot = true;
	canSpawn = true;
	damageTick = false;
	playerAlive = true;
}

Game::~Game() {

}
int Game::startGame() {
	float vel = 0.f;
	int direction = 0;
	sf::Event Event;
	while (window->pollEvent(Event))
	{
		switch (Event.type) { //checks if top right X is clicked
		case Event::Closed:
			window->close();
		}
	}
	if (playerAlive) { //Game has 2 screens, pre death and post death. Most of the game occurs pre death. This if is pre death, the else is post death.

		if (Keyboard::isKeyPressed(Keyboard::W)) player.playerAction(5.f, 1);   //if statements for movement;
		else if (Keyboard::isKeyPressed(Keyboard::S))player.playerAction(5.f, 5);
		if (Keyboard::isKeyPressed(Keyboard::D))player.playerAction(5.f, 3);
		else if (Keyboard::isKeyPressed(Keyboard::A))player.playerAction(5.f, 7);

		if (canShoot) { //when shoot is 0 you are allowed to shoot, but shooting starts a cooldown. 
			if (Mouse::isButtonPressed(Mouse::Left)) {
				canShoot = false;
				t = clock.getElapsedTime(); 
				player.shoot();

			}
		}
		if (!canShoot) {  //if you shot recently, this checks the time and if long enough has passed it re-enables shooting. 
			end = clock.getElapsedTime();
			if (end.asSeconds() - t.asSeconds() > player.getBulletSpeed()) { 

				canShoot = true;
			}
		}
		if (canSpawn) { //set to 0 by default, and reset to 0 after a cooldown. 
			canSpawn = false;
			this->spawnEnemy();
		}
		if (!canSpawn) { //if a zombie was made recently, it needs to wait a certain amount of time before switch is set back to 0 and spawning is allowed again
			endEnemy = clock.getElapsedTime();
			if (endEnemy.asSeconds() - tEnemy.asSeconds() > 1) canSpawn = true;

		}
		
		window->clear();   //clears window! 
		world.drawBackground(*window); //draws on the background
		this->updateEnemies();
		this->updateExplosions();
		for (int i = 0; i < enemyVector.size(); i++) {
			if (player.getBounds().intersects(enemyVector[i]->getBounds()) == true && enemyVector[i]->getAnimFinished() == true && damageTick == false) {
				damageTick = true;
				player.setHp(enemyVector[i]->dealDamage(player.getHp()), player.getMaxHp());
				tDeath = clock.getElapsedTime();
				break;
			}
		}
		if (damageTick == true) if (clock.getElapsedTime().asSeconds() - tDeath.asSeconds() > 2) damageTick = false;
		player.updatePlayer(*window);
		player.drawSprite(*window);


		ui.drawUI(*window);
		ui.updateUI(player.getHp(), player.getMaxHp(), player.getAmmo(), player.getMaxAmmo(), *window, score);
		ui.drawInstructions(*window);
		window->display();

		if (player.getHp() < 1) {
			playerAlive = false;
		}
	}
	else {

		window->clear();
		world.drawBackground(*window, "Textures/Death.png");
		window->display();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		time_t t = time(0);   // get time now
		struct tm* now = localtime(&t);
		fileS.open("scoreBoard.txt", ios::app);
		fileS << "\nPlayer1," << score << "," << (now->tm_year + 1900) << '/'
			<< (now->tm_mon + 1) << '/'
			<< now->tm_mday;
		return 0;
	}

	return 1;
}

Enemy* Game::makeEnemy() {
	float randomX = rand() % (window->getSize().x - 0 + 1) + 0;
	float randomY = rand() % (window->getSize().y - 0 + 1) + 0; //creates x and y for zombies to spawn in
	int ztype = rand() % (this->enemyWeight[0] + this->enemyWeight[1] + this->enemyWeight[2]);
	if (ztype < enemyWeight[0]) {
		return new ZombieNormal(*window, randomX, randomY);
	} 
	if (ztype < enemyWeight[0] + enemyWeight[1]) {
		return new ZombieLight(*window, randomX, randomY);
	}
	else {
		return new ZombieBig(*window, randomX, randomY);
	}
	
	return NULL;
}

void Game::updateExplosions() {
	for (int l = 0; l < explodeVector.size(); l++) {
		string lin = "Textures/Explosion";
		lin.append(to_string(explodeVector[l].state));
		lin.append(".png");
		explodeTexure.loadFromFile(lin);
		explodeSprite.setTexture(explodeTexure);
		explodeSprite.setOrigin(12, 12);
		explodeSprite.setPosition(explodeVector[l].xC, explodeVector[l].yC);
		window->draw(explodeSprite);
		if (explodeVector[l].state == 5) {
			explodeVector.erase(explodeVector.begin() + l);
			break;
		}
		explodeVector[l].state++;
	}
}

void Game::updateEnemies() {
	int j = 0;
	while (enemyVector.size() > j) { //loops through all enemies

		if (enemyVector[j]->getAnimFinished() == false) { //If the spawning animation has not finished, continue to iterate through the sprites
			// aniamtion
			if (clock.getElapsedTime().asSeconds() - tAnimation[j].asSeconds() > 0.1) {

				enemyVector[j]->enemySpawnAnim();
				tAnimation[j] = clock.getElapsedTime();
			}
			if (enemyVector[j]->getType() == 2) {
				dynamic_cast<ZombieBig*>(enemyVector[j])->drawSprite(*window); //big zombie has special function overloads, so Enemy pointers need to be tested for their type, and then cast to ZombieBig if they are a big zombie
			}
			else {
				enemyVector[j]->drawSprite(*window); //normal drawSprite
			}
		}
		else {
			//animation finished, moving

			int i = 0; //Bullet and Enemy Collision Check
			while (player.getBulletBoundary().size() > i) { //loops through each bulelt
				for (int j = 0; j < enemyVector.size(); j++) { //loops through each enemy for each bullet 
					if (player.getBulletBoundary()[i].getRect().getGlobalBounds().intersects(enemyVector[j]->getBounds()) == true && enemyVector[j]->getAnimFinished() == true) { //triggered if any bullet enemy pairs are overlapping
						if (enemyVector[j]->getType() == 2) {
							dynamic_cast<ZombieBig*>(enemyVector[j])->takeDamage(player.getDamage()); //big zombie takes damage
							dynamic_cast<ZombieBig*>(enemyVector[j])->enemyUpdate(Vector2f(player.getX(), player.getY()), 1); //special casting for big zombies
							dynamic_cast<ZombieBig*>(enemyVector[j])->drawSprite(*window);
						}
						else {
							enemyVector[j]->takeDamage(player.getDamage()); //Enemies take damage;
							enemyVector[j]->setSpeed(-enemyVector[j]->getSpeed() * 2);
						}
						if (enemyVector[j]->getHpEnemy() < 1) { //if the zombies take damage so that they die, the points are awarded (num) based on the type of zombie, and enemy is erased;
							int num = 0;
							num = enemyVector[j]->getType();
							if (num == 1) score += 30;
							else if (num == 2) score += 200;
							else if (num == 3) score += 50;
							delete enemyVector[j];
							enemyVector.erase(enemyVector.begin() + j);;
						}
						explodeVector.push_back({ player.getBulletBoundary()[i].getRect().getPosition().x, player.getBulletBoundary()[i].getRect().getPosition().y, 1 }); //takes the cordinates of the bullet and sets the bullet explosion animation to the first frame
						player.deleteBullet(i); //kills the bullet
						break;
					}
				}
				i++;
			}

			if (enemyVector[j]->getType() == 2) { //updates the enemies, then draws them onto the window; 
				dynamic_cast<ZombieBig*>(enemyVector[j])->enemyUpdate(Vector2f(player.getX(), player.getY()), 0); //special casting for big zombies
				dynamic_cast<ZombieBig*>(enemyVector[j])->drawSprite(*window);
			}
			else {
				enemyVector[j]->enemyUpdate(Vector2f(player.getX(), player.getY())); //no cast for others
				enemyVector[j]->drawSprite(*window);
			}
		}
		j++;
	}
}

void Game::spawnEnemy() {
	tEnemy = clock.getElapsedTime();
	if (eCounter <= enemyCount) {//if the amount of current enemies spawned so far is less than the intended amount to spawn, spawn an enemy. 
		enemyVector.push_back(this->makeEnemy()); //Zombie in Enemy pointer is pushed into the vector. 
		tAnimation.push_back(clock.getElapsedTime()); //records time for that zombie
		enemyCount--; //since we just created a zombie we an take it off the list of enemies to make. 

	}
}
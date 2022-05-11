#include "TestCases.h"

TestCases::TestCases() {
	std::cout << "CRINGE, get outa da default constructer bozo" << std::endl;
}

TestCases::TestCases(sf::RenderWindow& iwindow) {
	window = &iwindow;
	score = 0;
	enemyCount = 20;
	eCounter = 1;
	this->enemyWeight[0] = 8;
	this->enemyWeight[1] = 8;
	this->enemyWeight[2] = 1;
	canShoot = true;
	canSpawn = true;
	damageTick = false;
	playerAlive = true;
	test = 0;
	movementStage = 0;

	font.loadFromFile("Fonts/arial.ttf");
	this->option.setFont(this->font);
	this->option.setFillColor(sf::Color::Red);
	this->option.setCharacterSize(60);
	this->option.setPosition(30, 10.f); \
}
int TestCases::startTestCases() {
	if (test == 0) {
		sf::Event Event;
		while (window->pollEvent(Event))
		{
			switch (Event.type) { //checks if top right X is clicked
			case Event::Closed:
				window->close();
			}
		}
		this->option.setString("Test Case 1: Does the player follow the mouse (hit enter)");
		window->clear(sf::Color::Magenta);
		this->player.updatePlayer(*window);
		this->player.drawSprite(*window);
		window->draw(option);
		window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			test++;
		}
	}
	if (test == 1) {
		sf::Event Event;
		while (window->pollEvent(Event))
		{
			switch (Event.type) { //checks if top right X is clicked
			case Event::Closed:
				window->close();
			}
		}
		window->clear(sf::Color::Green);
		this->option.setString("Test Case 2: Does Player Movement Work");
		this->player.updatePlayer(*window);
		this->player.drawSprite(*window);
		window->draw(option);
		switch (movementStage) {
		case 0:
			player.playerAction(5, 1);
			if (player.getY() < (window->getSize().y * 1 / 4)) {
				movementStage++;
			}
			break;
		case 1:
			player.playerAction(5, 5);
			if (player.getY() > (window->getSize().y * 3 / 4)) {
				movementStage++;
			}
			break;
		case 2:
			player.playerAction(5, 7);
			if (player.getX() < (window->getSize().x * 1 / 4)) {
				movementStage++;
			}
			break;
		case 3:
			player.playerAction(5, 3);
			if (player.getX() > (window->getSize().x * 3 / 4)) {
				movementStage++;
			}
			break;
		case 4:
			test++;
			break;
		}
		window->display();
	}
	if (test == 2) {
		this->option.setString("Test Case 3: Does Zombie generation work?");
		window->clear(sf::Color::Blue);
		sf::Event Event;
		while (window->pollEvent(Event))
		{
			switch (Event.type) { //checks if top right X is clicked
			case Event::Closed:
				window->close();
			}
		}
		if (enemyCount) {
			this->spawnEnemy();
		}
		this->updateEnemies();
		if (!enemyCount) {
			this->option.setString("Test Case 3: Does Zombie generation work? (Hit enter)");

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				test++;
			}
		}
		window->draw(option);
		player.drawSprite(*window);
		window->display();
	}
	if (test == 3) {
		this->option.setString("Test Case 4: Does Shooting Work? (you aim)");
		window->clear(sf::Color::Blue);
		sf::Event Event;
		while (window->pollEvent(Event))
		{
			switch (Event.type) { //checks if top right X is clicked
			case Event::Closed:
				window->close();
			}
		}
		if (enemyCount) {
			this->spawnEnemy();
		}
		this->updateEnemies();
		window->draw(option);
		player.drawSprite(*window);
		if (canShoot) { //when shoot is 0 you are allowed to shoot, but shooting starts a cooldown. 
			canShoot = false;
			t = clock.getElapsedTime();
			player.shoot();

		}
		if (!canShoot) {  //if you shot recently, this checks the time and if long enough has passed it re-enables shooting. 
			end = clock.getElapsedTime();
			if (end.asSeconds() - t.asSeconds() > .1) {

				canShoot = true;
			}
		}
		this->player.updatePlayer(*window);
		updateExplosions();
		window->display();
		if (enemyVector.size() == 1) {
			test++;
			enemyCount = 20;
		}
	}
	sf::Text scoretxt;
	scoretxt.setFont(font);
	std::string strscore;
	if (test == 4) {
		strscore = "Test 5: Does Score go up when killing zombies, Score:";
		strscore.append(to_string(this->score));
		this->option.setString(strscore);
		window->clear(sf::Color::Cyan);
		sf::Event Event;
		while (window->pollEvent(Event))
		{
			switch (Event.type) { //checks if top right X is clicked
			case Event::Closed:
				window->close();
			}
		}
		if (enemyCount) {
			this->spawnEnemy();
		}
		this->updateEnemies();
		if (!enemyCount) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				test++;
			}
		}

		window->draw(option);
		player.drawSprite(*window);
		this->updateEnemies();
		window->draw(option);
		player.drawSprite(*window);
		if (canShoot) { //when shoot is 0 you are allowed to shoot, but shooting starts a cooldown. 
			canShoot = false;
			t = clock.getElapsedTime();
			player.shoot();

		}
		if (!canShoot) {  //if you shot recently, this checks the time and if long enough has passed it re-enables shooting. 
			end = clock.getElapsedTime();
			if (end.asSeconds() - t.asSeconds() > .1) {

				canShoot = true;
			}
		}
		this->player.updatePlayer(*window);
		updateExplosions();
		window->display();
		if (enemyVector.size() == 1) {
			test++;
		}

	}
	if (test == 5) {
		sf::Event Event;
		while (window->pollEvent(Event))
		{
			switch (Event.type) { //checks if top right X is clicked
			case Event::Closed:
				window->close();
			}
		}
		window->clear();
		option.setCharacterSize(40);
		strscore = "(Enter to return), you completed all the test cases and get a score of: ";
		strscore.append(to_string(score));
		option.setString(strscore);
		window->draw(option);
		window->display();

		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			return 0;
		}
	}


	return 4;
}
TestCases::~TestCases() {

}

Enemy* TestCases::makeEnemy() {
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

void TestCases::updateExplosions() {
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

void TestCases::updateEnemies() {
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
							if (enemyVector.size() == 1) {
								enemyVector.erase(enemyVector.begin());
							}
							else {
								enemyVector.erase(enemyVector.begin() + j);
							}
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

void TestCases::spawnEnemy() {
	tEnemy = clock.getElapsedTime();
	if (eCounter <= enemyCount) {//if the amount of current enemies spawned so far is less than the intended amount to spawn, spawn an enemy. 
		enemyVector.push_back(this->makeEnemy()); //Zombie in Enemy pointer is pushed into the vector. 
		tAnimation.push_back(clock.getElapsedTime()); //records time for that zombie
		enemyCount--; //since we just created a zombie we an take it off the list of enemies to make. 

	}
}
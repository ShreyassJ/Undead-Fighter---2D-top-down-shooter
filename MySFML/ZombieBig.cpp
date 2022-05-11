#include "ZombieBig.h"

ZombieBig::ZombieBig(RenderWindow& window, float x, float y) {
	// constructor is ised to give this zombie different attributes than the standard one from the enemy.cpp class
	hp = 40;
	enemyStyle = 2;
	enemyAnim = "";
	spriteState = 16;
	speed = 1;
	damage = 10;
	anger = 0;
	angerThreshold = 15;
	decrease = 200;
	counter = 0;
	this->setSprite(false, this->sprite);
	sprite.setScale(3.f, 3.f);
	sprite.setOrigin(25, 25);
	animFinieshed = false;
	sprite.setPosition(x, y);
}

void ZombieBig::enemyUpdate(Vector2f playerPos, int num) {

	// (enemyUpdate is exactly the same as the one from enemy.cpp with additional code commented on below)
	float mX = playerPos.x;
	float mY = playerPos.y;
	float sX = sprite.getPosition().x;
	float sY = sprite.getPosition().y;

	// if else statment is used to calcaulted knockback
	// the big zombie has a special rage mode so if the zombie is hit (num = 1) then it is stalled for a half second
	if (num == 1 && counter == 0) {
		cout << speed << endl;
		speed = -(speed * 3);
		if (counter == 0) {
			time = clock.getElapsedTime();
			counter = 1;
		}

	}
	else if (num == 0 && counter == 1) {
		// stalled for half second:
		if (clock.getElapsedTime().asSeconds() - time.asSeconds() > 0.5) {
			counter = 0;
		}
	}
	else {
		// once the stall has finished the rage mode is activated and he rushes the player
		if (angerThreshold < anger) {
			speed = 25;
			anger--;
			if (angerThreshold == anger) {
				anger = 0;
			}
		}
		// the only way to not get hit is to constantly shoot the big zombie so it is constantly stalled
	}
	float turn = atan2(mX - sX, mY - sY);
	turn *= 180 / 3.141592;
	turn = -turn;
	sprite.setRotation(turn);
	enemyMove(turn);
	speed = 1;
}

void ZombieBig::takeDamage(int dmg) {
	// when it has taken damage it enters rage mode:
	this->hp = this->hp - dmg;
	anger = anger + 15;
	std::cout << "GAH";
}
void ZombieBig::drawSprite(RenderWindow& window) {
	//draws the sprite
	texture.loadFromFile(enemyAnim);
	sprite.setTexture(texture);
	window.draw(sprite);
	sprite.rotate(180);
	window.draw(sprite);
	sprite.rotate(180);
}
void ZombieBig::AngerDash(Vector2f playerPos) {
	// angerDash is not used, ignore
	float mX = playerPos.x;
	float mY = playerPos.y;
	float sX = sprite.getPosition().x;
	float sY = sprite.getPosition().y;
	float turn = atan2(mX - sX, mY - sY);
	turn *= 180 / 3.141592;
	turn = -turn;
	sprite.setRotation(turn);
	float rad = 3.1415926536 / 360 * turn * 2;
	sprite.move(sin(rad) * -200, cos(rad) * (200));
}
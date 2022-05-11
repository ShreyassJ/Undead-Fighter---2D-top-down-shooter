#include "ZombieNormal.h"
ZombieNormal::ZombieNormal(RenderWindow& window, float x, float y) {
	// sets characteristics for the normal zombie:
	hp = 12;
	enemyStyle = 1;
	enemyAnim = "";
	spriteState = 16;
	speed = 3;
	damage = 3;

	this->setSprite(false, sprite);
	sprite.setOrigin(25, 25);
	animFinieshed = false;
	sprite.setPosition(x, y);
}

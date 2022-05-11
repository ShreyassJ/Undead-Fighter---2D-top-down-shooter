#include "ZombieLight.h"
ZombieLight::ZombieLight(RenderWindow& window, float x, float y) {
	// set chracteristics for the light zombie
	hp = 3;
	enemyStyle = 3;
	enemyAnim = "";
	spriteState = 16;
	speed = 5;
	damage = 1;
	this->setSprite(false, sprite);
	sprite.setOrigin(25, 25);
	animFinieshed = false;
	sprite.setPosition(x, y);
}

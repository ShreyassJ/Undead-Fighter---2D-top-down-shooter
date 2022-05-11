#include "Enemy.h"
void Enemy::enemySpawnAnim() {
	// checks to see if the aniamtion for spawning the sprite is finsihed
	setSprite(true, sprite);
	if (spriteState == 0) {
		animFinieshed = true;
	}

}
void Enemy::setspriteState(int idata) {
	// the sprite has 16 stages for its spawning aniamtion
	// this setter sets it to the next stage when called
	this->spriteState = idata;
}
void Enemy::setSprite(bool spawn, Sprite &sprt) {
	if (spawn == true) {
		spriteState--;
	}
	//code below is used to create the sring to call a specific sprite in the animation
	enemyAnim = "";
	enemyAnim.append("Textures/Enemies/Enemy");
	enemyAnim.append(to_string(enemyStyle));
	enemyAnim.append("-");
	enemyAnim.append(to_string(spriteState));
	enemyAnim.append(".png");
	texture.loadFromFile(enemyAnim);
	sprt.setTexture(texture);
}
void Enemy::enemyMove(float turn) {
	// converts degrees to radians
	float rad = 3.1415926536 / 360 * turn * 2;
	// uses given rotation to move in a specific direction
	sprite.move(sin(rad) * -speed, cos(rad) * (speed));
}
void Enemy::enemyUpdate(Vector2f playerPos) {
	// this fucntion is used to make sure that the enemy sprite is facing the player
	// first it finds the player position:
	float mX = playerPos.x;
	float mY = playerPos.y;
	// then the enemy sprite position:
	float sX = sprite.getPosition().x;
	float sY = sprite.getPosition().y;
	// the fucntion , arctan-1(x / y) gives the anlge between 2 seperate points
	// float turn below uses the equation above to calcaulte the rotation (in degrees)
	float turn = atan2(mX - sX, mY - sY);

	// the angle is then converted to radians
	turn *= 180 / 3.141592;
	// then flipped since the enemy sprite is facing the oppsite way
	turn = -turn;
	// then the rotation is set and the enemy moves 
	sprite.setRotation(turn);
	enemyMove(turn);

	// if the enemy has taken knockback the speed is then multipled by (-1) in order to reset the enemy's pathing
	if (speed < 0) {
		speed = speed / 2 * -1;
	}
}
int Enemy::getHpEnemy() {
	return this->hp;
}
void Enemy::setSpeed(int idata) {
	this->speed = idata;
}
int Enemy::getSpeed(){
	return this->speed;
}
void Enemy::setHpEnemy(int HP) {
	this->hp = HP;
}
void Enemy::takeDamage(int dmg) {
	this->hp = this->hp - 3;
}
int Enemy::dealDamage(int pHp) {
	return pHp - damage;
}
int Enemy::getType() {
	return this->enemyStyle;
}

void Enemy::drawSprite(RenderWindow& window) {
	texture.loadFromFile(enemyAnim);

	sprite.setTexture(texture);
	window.draw(sprite);
}

bool Enemy::getAnimFinished() {
	return animFinieshed;
}

FloatRect Enemy::getBounds() {
	return sprite.getGlobalBounds();
}
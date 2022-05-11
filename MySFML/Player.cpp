#include "Player.h"
Player::Player() {
	hpMax = 25;// set hp
	hp = hpMax;
	speed = 1;	// set speed
	// set sprite:
	texture.loadFromFile("Textures/Player2.png"); 
	sprite.setTexture(texture);
	sprite.setOrigin(25, 25);
	sprite.setPosition(775.0f, 485.0f);
}
void Player::shoot() {
	// shoot gun:
	gun.shoot();
}
void Player::setSpritePos(float xVal, float yVal) {
	sprite.setPosition(xVal, yVal);
}
void Player::drawSprite(RenderWindow& window) {
	window.draw(sprite);
	gun.drawSprite(window);
}
void Player::updatePlayer(RenderWindow& window) {
	// this function makes sure the player is facing the mouse pointer
	// first we get the mouse pointer location:
	float mX = Mouse::getPosition(window).x;
	float mY = Mouse::getPosition(window).y;
	// then the enemy sprite position:
	float sX = sprite.getPosition().x;
	float sY = sprite.getPosition().y;
	// the fucntion , arctan-1(x / y) gives the anlge between 2 seperate points
	// float turn below uses the equation above to calcaulte the rotation (in degrees)
	float turn = atan2(mX - sX, mY - sY);

	// the angle is then converted to radians
	turn *= 180 / 3.141592;
	// then flipped since sprite faces the opposite way
	turn = -turn;
	sprite.setRotation(turn);
	// we also need set the weapon in the same direction and position of the player:
	gun.weaponUpdate(turn, sprite.getPosition().x, sprite.getPosition().y, window);
}
void Player::playerAction(float Speed, int direction) {
	switch (direction)
	{
	case 1:
		// up
		if (sprite.getPosition().y > 0) sprite.move(0.f, (-Speed) * speed);
		break;
	case 2:
		break;
	case 3:
		// right
		if (sprite.getPosition().x < 1600) sprite.move((Speed)*speed, 0.f);
		break;
	case 4:
		break;
	case 5:
		// down
		if (sprite.getPosition().y < 900) sprite.move(0.f, (Speed)*speed);
		break;
	case 6:
		break;
	case 7:
		// left
		if (sprite.getPosition().x > 0) sprite.move((-Speed) * speed, 0.f);
		break;
	case 8:
		break;
	default:
		break;
	}
}
//deletes bullet
void Player::deleteBullet(int b) {
	gun.deleteBullet(b);
}

// getters and setters:
vector<Bullet> Player::getBulletBoundary() {
	return gun.getBulletBounds();
}

int Player::getMaxAmmo() {
	return gun.getMaxAmmo();
}
int Player::getAmmo() {
	return gun.getAmmo();
}
float Player::getBulletSpeed() {
	return gun.getBulletSpeed();
}

float Player::getX() {
	return sprite.getPosition().x;
}
float Player::getY() {
	return sprite.getPosition().y;
}

int Player::getMaxHp() {
	return hpMax;
}
int Player::getHp() {
	return hp;
}
float Player::getSpeed() {
	return speed;
}


void Player::setMaxAmmo(int Ammo, int AmmoMax) {
	gun.setMaxAmmo(Ammo, AmmoMax);
}
void Player::setAmmo(int Ammo, int AmmoMax) {
	gun.setAmmo(Ammo, AmmoMax);
}



void Player::setMaxHp(int HP, int HPMax) {
	if (HPMax < HP) {
		hp = hpMax;
	}
	hpMax = HPMax;
}
void Player::setHp(int HP, int HPMax) {
	if (HP > HPMax) {
		hp = HPMax;
	}
	else hp = HP;
}
void Player::setSpeed(float Speed) {
	speed = Speed;
}

FloatRect Player::getBounds() {
	return sprite.getGlobalBounds();
}
int Player::getDamage() {
	return gun.getDamage();
}
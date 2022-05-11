#include "Bullet.h"
Bullet::Bullet() {
	std::cout << "Error: Bullet Default Constructer Called. Should not be used" << std::endl;
}
Bullet::Bullet(float ang, Vector2f dim) {
	// This contructor creates the bullet
	b.setSize(dim);
	b.setFillColor(Color::Yellow);
	// the angle is given with the float and
	// it is rotated 180 degrees in order to face the right difretion as well
	setAngle(ang + 180);
	t = clock.getElapsedTime();
}
Bullet::~Bullet() {
}
void Bullet::moveBullet(Vector2f pos, float dir) {
	// this moves the bullet in the direction of the bullets angle
	b.setRotation(dir);
	b.setPosition(pos);
	setXPos(pos.x);
	setYPos(pos.y);

}
void Bullet::drawSprite(RenderWindow& window) {
	window.draw(b);
}
void Bullet::shootB(float speed) {
	// converts the agel to radians
	float rad = 3.1415926536 / 360 * dirA * 2;
	// equation moves the sprite in direction given by the radains
	b.move(sin(rad) * speed, cos(rad) * (-speed));
}

//getters and setters:
float Bullet::getXPos() {
	return xPos;
}
float Bullet::getYPos() {
	return yPos;
}
void Bullet::setXPos(float XPos) {
	xPos = XPos;
}
void Bullet::setYPos(float YPos) {
	yPos = YPos;
}
void Bullet::setAngle(float Angle) {
	dirA = Angle;
}
Time Bullet::getTime() {
	return t;
}
Clock Bullet::getClock() {
	return clock;
}
RectangleShape Bullet::getRect() {
	return b;
}
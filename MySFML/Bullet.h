#ifndef BULLET_H
#define BULLET_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
class Bullet {
private:
	float xPos;
	float yPos;
	float dirA;
	RectangleShape b;
	Clock clock;
	Time t;
public:
	Bullet();
	Bullet(float ang, Vector2f dim);
	~Bullet();
	void moveBullet(Vector2f pos, float dir);
	void drawSprite(RenderWindow& window);
	void shootB(float speed);
	float getXPos();
	float getYPos();
	void setXPos(float XPos);
	void setYPos(float YPos);
	void setAngle(float Angle);
	Time getTime();
	Clock getClock();
	RectangleShape getRect();
};

#endif BULLET_H
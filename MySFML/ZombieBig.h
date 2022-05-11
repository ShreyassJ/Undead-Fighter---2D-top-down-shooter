#ifndef ZOMBIEBIG_H
#define ZOMBIEBIG_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Enemy.h"

using namespace std;
using namespace sf;

class ZombieBig : public Enemy {
private:
	int anger;
	int angerThreshold;
	float decrease;
	int counter;
	Clock clock;
	Time time;
public:
	ZombieBig(RenderWindow& window, float x, float y);
	void enemyUpdate(Vector2f playerPos, int num);
	void drawSprite(RenderWindow& window);
	void takeDamage(int dmg);
	void AngerDash(Vector2f playerPos);
	void getOutaMyHead(){}
};

#endif // !ZOMBIEBIG_H

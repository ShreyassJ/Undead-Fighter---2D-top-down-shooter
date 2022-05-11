#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Enemy
{
protected:
	int hp;
	int spriteState;
	Texture texture;
	Sprite sprite;
	string enemyAnim;

	float speed;

	int enemyStyle;
	int damage;
	bool animFinieshed;
public:
	virtual void getOutaMyHead() = 0;
	void setspriteState(int idata);
	void enemySpawnAnim();
	void setSpeed(int idata);
	int getSpeed();
	void setSprite(bool spawn, Sprite& sprt);
	void enemyMove(float turn);
	void enemyUpdate(Vector2f playerPos);
	int getHpEnemy();
	void setHpEnemy(int HP);
	int dealDamage(int pHp);
	void takeDamage(int dmg);
	int getType();
	void drawSprite(RenderWindow& window);
	bool getAnimFinished();
	FloatRect getBounds();
};
#endif ENEMY_H

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Bullet.h"
#include "Weapon.h"

using namespace std;
using namespace sf;
class Player {
private:

	int hpMax;
	int hp;

	/*int ammoMax;
	int ammo;*/

	/*int damage;*/
	float speed;

	Texture texture;
	Sprite sprite;

	Weapon gun;
public:
	Player();
	void shoot();

	void drawSprite(RenderWindow& window);
	void updatePlayer(RenderWindow& window);
	void playerAction(float Speed, int direction);



	int getMaxAmmo();
	int getAmmo();
	float getBulletSpeed();
	float getX();
	float getY();

	int getMaxHp();
	int getHp();
	/////*int getDamage() {
	////	return damage;
	////}*/
	float getSpeed();


	void setMaxAmmo(int Ammo, int AmmoMax);
	void setAmmo(int Ammo, int AmmoMax);



	void setMaxHp(int HP, int HPMax);
	void setHp(int HP, int HPMax);
	/////*void setDamage(int Damage) {
	////	damage = Damage;
	////}*/
	void setSpeed(float Speed);
	vector<Bullet> getBulletBoundary();
	void deleteBullet(int b);
	FloatRect getBounds();
	int getDamage();

	void setSpritePos(float xVal, float yVal);
};

#endif // !PLAYER_H

#ifndef WEAPON_H
#define WEAPON_H


#include <vector>
#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Bullet.h"

using namespace std;
using namespace sf;
class Weapon {
private:
	Texture texture;
	Sprite sprite;

	int ammoMax;
	int ammo;

	float angle;

	float bulletSpeed;

	int damage;// may move to bullet class

	vector<Bullet> gBullet;
	vector<FloatRect> bulletBoundary;
public:
	Weapon();
	void shoot();
	void weaponUpdate(float turn, float x, float y, RenderWindow& window);
	void deleteBullet(int bullet);
	vector<Bullet> getBulletBounds();
	void drawSprite(RenderWindow& window);
	void setMaxAmmo(int Ammo, int AmmoMax);
	void setAmmo(int Ammo, int AmmoMax);
	void setDamage(int Damage);
	void setBulletSpeed(float bSpeed);
	float getBulletSpeed();
	int getMaxAmmo();
	int getAmmo();
	int getDamage();
	float getX();
	float getY();
};

#endif // !WEAPON_H


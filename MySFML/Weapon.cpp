#include "Weapon.h"


Weapon::Weapon() {
		ammoMax = 120;
		ammo = 120;
		bulletSpeed = 0.2;
		damage = 3;// may move to bullet class
		// load sprite for weapon:
		texture.loadFromFile("Textures/pistol.png");
		sprite.setTexture(texture);
		sprite.setOrigin(5, -5);
		sprite.setPosition(775.0f, 490.0f);


	}
	void Weapon::shoot() {
		// when shoot function is called a bullet is created
		Bullet createB(angle, Vector2f(20, 5));
		// the bullet postion angle is set ahead of time:
		createB.moveBullet(Vector2f(sprite.getPosition().x, sprite.getPosition().y), angle + 90);
		// the bullet is pushed onto a vector:
		gBullet.push_back(createB);
	}


	void Weapon::weaponUpdate(float turn, float x, float y, RenderWindow& window) {
		// this fucntiopn sets the wepaon at the same posiiton and agnle as the player
		angle = turn;
		sprite.setPosition(x, y);
		sprite.setRotation(turn);
		int i = 0;
		// this fucntion also runs thoruhg every bullet currently displayed and moves it a frame ahead:
		while (gBullet.size() > i) {
			gBullet[i].drawSprite(window);
			gBullet[i].shootB(30);
			// the if statment below uses Time in order to check how long the bullet has been displayed since it was shot
			// if it has been more than 0.5 seconds it is deleted:
			if (gBullet[i].getClock().getElapsedTime().asSeconds() - gBullet[i].getTime().asSeconds() > 0.5) {
				gBullet.erase(gBullet.begin() + i);
			}
			i++;
		}
	}
	void Weapon::deleteBullet(int bullet) {
		// deletes bullet
		gBullet.erase(gBullet.begin() + bullet);
	}
	//draws gun:
	void Weapon::drawSprite(RenderWindow& window) {
		window.draw(sprite);
	}


	//setters and getter:
	vector<Bullet> Weapon::getBulletBounds() {
		return gBullet;
	}

	void Weapon::setMaxAmmo(int Ammo, int AmmoMax) {
		if (AmmoMax < Ammo) {
			ammo = AmmoMax;
		}
		ammoMax = AmmoMax;
	}
	void Weapon::setAmmo(int Ammo, int AmmoMax) {
		if (Ammo > AmmoMax) {
			ammo = AmmoMax;
		}
		else ammo = Ammo;
	}
	void Weapon::setDamage(int Damage) {
		damage = Damage;
	}

	void Weapon::setBulletSpeed(float bSpeed) {
		bulletSpeed = bSpeed;
	}

	float Weapon::getBulletSpeed() {
		return bulletSpeed;
	}

	int Weapon::getMaxAmmo() {
		return ammoMax;
	}
	int Weapon::getAmmo() {
		return ammo;
	}

	int Weapon::getDamage() {
		return damage;
	}

	float Weapon::getX() {
		return sprite.getPosition().x;
	}
	float Weapon::getY() {
		return sprite.getPosition().y;
	}
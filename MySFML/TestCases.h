#ifndef TestCases_H
#define TestCases_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<fstream>
#include<vector>
#include<string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Bullet.h"
#include "Weapon.h"
#include "Player.h"
#include "World.h"
#include "UI.h"
#include "Enemy.h"
#include "ZombieBig.h"
#include "ZombieNormal.h"
#include "ZombieLight.h"
using namespace std;

class TestCases {
private:
	struct bound { float xC; float yC; int state; };
	sf::RenderWindow* window; //shallow copy of window in menu, should not be deleted
	Texture explodeTexure;
	Sprite explodeSprite;
	//TestCases components
	Player player;
	World world;
	UI ui;
	//stuff used for spawning enemies
	vector<Enemy*> enemyVector;
	vector<bound> explodeVector;
	vector<Time> tAnimation;
	//keep track of various timers
	sf::Clock clock;
	sf::Time t;
	sf::Time end;
	sf::Time tEnemy;
	sf::Time endEnemy;
	sf::Time explosionDelay;
	sf::Time tDeath;
	int score;
	int level;
	int enemyCount;
	int eCounter;
	bool canShoot;
	bool canSpawn;
	bool damageTick;
	bool playerAlive;
	int enemyWeight[3];
	//for storing scores
	fstream fileS;
	int test;
	int movementStage;

	sf::Font font;
	sf::Text option;
public:
	TestCases();
	TestCases(sf::RenderWindow& iwindow);
	~TestCases();
	int startTestCases();
	Enemy* makeEnemy();
	void spawnEnemy();
	void updateExplosions();
	void updateEnemies();
};

#endif // !TestCases_H

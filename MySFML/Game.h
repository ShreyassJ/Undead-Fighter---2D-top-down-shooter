#ifndef GAME_H
#define GAME_H
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

class Game {
private:
	struct bound { float xC; float yC; int state; };
	sf::RenderWindow* window; //shallow copy of window in menu, should not be deleted
	Texture explodeTexure;
	Sprite explodeSprite;
	//Game components
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
public:
	Game();
	Game(sf::RenderWindow& iwindow);
	~Game();
	int startGame();
	Enemy* makeEnemy();
	void spawnEnemy();
	void updateExplosions();
	void updateEnemies();
};

#endif // !GAME_H

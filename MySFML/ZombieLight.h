#ifndef ZOMBIELIGHT_H
#define ZOMBIELIGHT_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Enemy.h"

using namespace std;
using namespace sf;

class ZombieLight : public Enemy {
private:


public:
	ZombieLight(RenderWindow& window, float x, float y);
	void getOutaMyHead(){}
};

#endif // !ZOMBIELIGHT_H

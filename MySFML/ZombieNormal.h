#ifndef ZOMBIENORMAL_H
#define ZOMBIENORMAL_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Enemy.h"

using namespace std;
using namespace sf;

class ZombieNormal : public Enemy {
private:


public:
	ZombieNormal(RenderWindow& window, float x, float y);
	void getOutaMyHead(){}
};

#endif // !ZOMBIENORMAL_H

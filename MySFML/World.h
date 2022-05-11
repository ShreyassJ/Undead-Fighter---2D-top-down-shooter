#ifndef WORLD_H
#define WORLD_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
class World {
private:
	Texture texture;
	Sprite sprite;
public:
	World();
	void drawBackground(RenderWindow& window);
	void drawBackground(RenderWindow& window, string str);
};


#endif // !WORLD_H

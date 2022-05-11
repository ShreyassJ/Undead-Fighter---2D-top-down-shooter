#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Settings {
private:
	sf::Text option1;
	sf::Text option2;
	sf::Text option3;
	sf::Font font;
	float indent;
	sf::RenderWindow* window;
public:
	Settings();
	Settings(sf::RenderWindow& iwindow);
	~Settings();
	int running();
};

#endif // !SETTINGS_H



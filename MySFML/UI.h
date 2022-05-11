#ifndef UI_H
#define UI_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;

class UI {
private:
	sf::Font font;
	sf::Text tHpBar;
	string hp;
	sf::Text tAmmo;
	string ammo;
	sf::Text instructions[6];
	sf::Text Points;
public:
	UI();
	void updateUI(int hp, int maxHP, int ammo, int maxAmmo, sf::RenderWindow& window, int points);
	void drawUI(sf::RenderWindow& window);
	void setInstructions();
	void drawInstructions(sf::RenderWindow& window);
	string getHPUI(int hp, int maxHP);
	string getAmmoUI(int ammo, int maxAmmo);
	string getPointsUI(int points);
};

#endif UI_H
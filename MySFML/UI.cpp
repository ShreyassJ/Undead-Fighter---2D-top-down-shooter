#include "UI.h"

UI::UI() {
	if (!font.loadFromFile("Fonts/Retro_Gaming.ttf")) cout << "error" << endl;
	//if (!font.loadFromFile("Fonts/zagreb_underground.ttf")) cout << "error" << endl;

	// set text for hp bar
	tHpBar.setFont(font);
	tHpBar.setCharacterSize(24);

	tHpBar.setFillColor(sf::Color::Red);
	tHpBar.setString("0 / 0");
	// set text for points bar
	Points.setFont(font);
	Points.setCharacterSize(24);

	Points.setFillColor(sf::Color::Black);
	Points.setString("Points - ");
	Points.setPosition(0, 25);
	// set instructions function:
	this->setInstructions();

}

void UI::updateUI(int hp, int maxHP, int ammo, int maxAmmo, sf::RenderWindow& window, int points) {
	// updateUI is called continously in game.cpp in order to update header
	tHpBar.setString(getHPUI(hp, maxHP));
	Points.setString(getPointsUI(points));
	drawUI(window);
}

void UI::setInstructions() {
	// sets text for instructions:
	for (int i = 0; i < 7; i++) {

		this->instructions[i].setFont(this->font);
		this->instructions[i].setFillColor(sf::Color::Black);
		this->instructions[i].setCharacterSize(20);
		this->instructions[i].setPosition(0.f, 50.f + (25.f * i));
	}
	this->instructions[0].setString("How to fight the zombies");
	this->instructions[1].setString("[W] to move up");
	this->instructions[2].setString("[A] to move left");
	this->instructions[3].setString("[S] to move down");
	this->instructions[4].setString("[D] to move right");
	this->instructions[5].setString("Left Click to shoot");
	this->instructions[6].setString("Space Bar to return to menu");
}

void UI::drawInstructions(sf::RenderWindow& window) {
	// loops trhough and draws every instruction
	for (int i = 0; i < 7; i++) {
		window.draw(this->instructions[i]);
	}
}

void UI::drawUI(sf::RenderWindow& window) {
	// draws hp and points bar to window
	window.draw(tHpBar);
	window.draw(Points);
}

string UI::getHPUI(int hp, int maxHP) {
	// sets string for hp abr
	string HP = "";
	HP.append(to_string(maxHP));
	HP.append(" / ");
	HP.append(to_string(hp));
	return HP;
}

string UI::getAmmoUI(int ammo, int maxAmmo)
{
	// sets string for ammo bar (not used)
	string Ammo;
	Ammo.append(to_string(maxAmmo));
	Ammo.append(" / ");
	Ammo.append(to_string(ammo));
	return Ammo;
}
string UI::getPointsUI(int points)
{
	// sets string for points bar
	string s = "";
	s.append("Points - ");
	s.append(to_string(points));
	return s;
}


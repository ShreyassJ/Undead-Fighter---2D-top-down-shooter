#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Settings.h"
#include "Scores.h"
#include "Bullet.h"
#include "Weapon.h"
#include "Player.h"
#include "UI.h"
#include "World.h"
#include "Game.h"
#include "TestCases.h"
class Menu {
private:
	//Where buttons lead
	Game* theGame;
	Settings* theSettings;
	Scores* theScores;
	TestCases* theTest;
	//for formatting stuff on screen
	int score;
	int width;
	int height;
	int windowPlace;
	float indent;
	sf::RenderWindow window;
	//fonts used
	sf::Font arial;
	sf::Font zagreb;
	//text on screen
	sf::Text titleText;
	sf::Text playText;
	sf::Text settingsText;
	sf::Text scoresText;
	sf::Text exitText;
	sf::Text tCases;


	//private methods
	void settings();  //takes you to settings page
	void playGame();  //takes you to play the game
	void checkScores(); //takes you to check on the leaderboard
	void testCase(); //takes you to the test casesx`
	//mainMenu Pieces;
	int textClicked(sf::Text& text, float mouseX, float mouseY); //checks if text refrence was clicked on, returns 1 if it was, 0 otherwise
	void mainMenu(); //this is the interface you use to navigate between the game, settings, and leadboards
public:
	//construct destruct; 
	Menu();
	~Menu();
	//one function to rule them all. Only thing other than declaring a Menu that should be in mian. 
	void fullLoop();
};
#endif // !MENU_H

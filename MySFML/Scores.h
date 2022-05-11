#ifndef SCORES_H
#define SCORES_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Scores { //this is where leadboard/scoreboard stuff should go 
private:
	sf::Font fontTitle;
	sf::Font font;
	sf::RenderWindow* window;
	sf::Text Title;
	fstream scoreFile;
	struct sc { string name; int score; string date; };
	vector<sc> scoreFin;
	bool loaded;
	string line;
	sf::Text lineFin;
	sf::Text ret;
public:
	Scores();
	Scores(sf::RenderWindow& iwindow);
	~Scores();
	int running();
	void loadScores();
	void printScores();
};



#endif // !SCORES_H

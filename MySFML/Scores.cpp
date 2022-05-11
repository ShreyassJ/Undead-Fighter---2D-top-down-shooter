#include "Scores.h"

Scores::Scores() {

}

Scores::Scores(sf::RenderWindow& iwindow) {
	this->window = &iwindow;
	loaded = false;
	line = "";
	//loads all the text with location color size etc
	this->fontTitle.loadFromFile("Fonts/zagreb_underground.ttf");
	this->font.loadFromFile("Fonts/arial.ttf");
	this->lineFin.setFont(this->fontTitle);
	this->Title.setFont(this->fontTitle);
	this->lineFin.setFillColor(sf::Color::White);
	this->Title.setFillColor(sf::Color::White);
	this->lineFin.setCharacterSize(40);
	this->Title.setCharacterSize(200);
	this->Title.setString("SCOREBOARD");
	this->Title.setPosition(window->getSize().x / 2 - this->Title.getGlobalBounds().width / 2, 20.f);
	this->ret.setFont(this->font);
	this->ret.setFillColor(sf::Color::Red);
	this->ret.setCharacterSize(50);
	this->ret.setString("Return to Menu");
	this->ret.setPosition(window->getSize().x - (this->ret.getGlobalBounds().width * 10 / 9), window->getSize().y - (this->ret.getGlobalBounds().height * 2));
}
Scores::~Scores() {

}
int Scores::running() {
	if (loaded == false) {
		//calls laod scores function ( loads form txt file)
		loadScores();
		// sorts using sort function specifically used for vectors in order to display high scores at the top
		sort(scoreFin.begin(), scoreFin.end(), [](sc num1, sc num2) { return num1.score > num2.score; });
		loaded = true;
	}
	sf::Event Event;
	while (window->pollEvent(Event))
	{
		switch (Event.type) {
		case sf::Event::Closed:
			window->close();
		}
	}
	// display code:
	window->clear();
	window->draw(Title);
	printScores();
	window->draw(ret);
	window->display();


	// code below is used to see if user clicked on return to menu button
	float mouseX = sf::Mouse::getPosition(*window).x;
	float mouseY = sf::Mouse::getPosition(*window).y;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if ((ret.getPosition().x < mouseX) && (mouseX < ret.getPosition().x + ret.getGlobalBounds().width)) {
			if ((ret.getPosition().y < mouseY) && (mouseY < ret.getPosition().y + ret.getGlobalBounds().height)) {
				return 0;
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		return 0;
	}
	return 3;
}
void Scores::loadScores() {
	//file with all the scores:
	scoreFile.open("scoreBoard.txt");
	string line;
	getline(scoreFile, line);

	//uses strtok to to parse through txt file
	while (!scoreFile.eof()) {
		char* token;
		string s1 = "";
		string s2 = "";
		string s3 = "";
		getline(scoreFile, line);
		char ar[500];
		strcpy(ar, line.c_str());
		token = strtok(ar, ",");
		s1 = token;
		token = strtok(NULL, ",");
		s2 = token;
		token = strtok(NULL, ",");
		s3 = token;
		// pushed onto a struct vector containing name score and date:
		scoreFin.push_back({ s1, stoi(s2), s3 });
	}
	scoreFile.close();
}
void Scores::printScores() {
	// header for scoreboard:
	line.append("NAME       SCORE       DATE");
	lineFin.setString(line);
	this->lineFin.setPosition(window->getSize().x / 2 - this->lineFin.getGlobalBounds().width / 2, 270);
	window->draw(lineFin);
	// makes sure only top 10 socres are displayed
	int num = 0;
	if (scoreFin.size() > 10)num = 10;
	else num = scoreFin.size();
	// loops through entire list 10 times dispalying the top 10 scores
	for (int i = 0; i < num; i++) {
		line = "";
		line.append(scoreFin[i].name);
		line.append("     ");
		line.append(to_string(scoreFin[i].score));
		line.append("     ");
		line.append(scoreFin[i].date);
		lineFin.setString(line);
		this->lineFin.setPosition(window->getSize().x / 2 - this->lineFin.getGlobalBounds().width / 2, 320 + (50.f * i));
		window->draw(lineFin);
	}

}



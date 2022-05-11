#include "Settings.h"

Settings::Settings() {

}
Settings::Settings(sf::RenderWindow& iwindow) {
	// code used to disaply option avlaible in seetings tab:
	// sets font, color, size, string, and position:
	this->window = &iwindow;
	this->font.loadFromFile("Fonts/arial.ttf");
	this->option1.setFont(this->font);
	this->option2.setFont(this->font);
	this->option3.setFont(this->font);
	this->option1.setFillColor(sf::Color::Red);
	this->option2.setFillColor(sf::Color::Red);
	this->option3.setFillColor(sf::Color::Red);
	this->option1.setCharacterSize(100);
	this->option2.setCharacterSize(50);
	this->option3.setCharacterSize(50);
	this->option1.setString("Settings");
	this->option2.setString("Return to Menu");
	this->option3.setString("More coming soon!");
	this->indent = window->getSize().x / 2 - this->option1.getGlobalBounds().width / 2;
	this->option1.setPosition(indent, 10.f);
	this->option2.setPosition(window->getSize().x - (this->option2.getGlobalBounds().width * 10 / 9), window->getSize().y - (this->option2.getGlobalBounds().height * 2));
	this->option3.setPosition(window->getSize().x / 2 - this->option3.getGlobalBounds().width / 2, window->getSize().y / 2 - this->option3.getGlobalBounds().height / 2);
}

Settings::~Settings() {

}

int Settings::running() {
	sf::Event Event;
	while (window->pollEvent(Event))
	{
		switch (Event.type) {
		case sf::Event::Closed:
			window->close();
		}



	}
	// draws all the texts onto the window:
	window->clear();
	window->draw(option1);
	window->draw(option2);
	window->draw(option3);
	window->display();
	//checks if player clciked the return to menu text:
	float mouseX = sf::Mouse::getPosition(*window).x;
	float mouseY = sf::Mouse::getPosition(*window).y;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if ((option2.getPosition().x < mouseX) && (mouseX < option2.getPosition().x + option2.getGlobalBounds().width)) {
			if ((option2.getPosition().y < mouseY) && (mouseY < option2.getPosition().y + option2.getGlobalBounds().height)) {
				return 0;
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		return 0;
	}
	return 2;
}
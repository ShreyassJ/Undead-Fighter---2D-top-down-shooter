#include "Menu.h"

Menu::Menu(){
    //set window information
	this->score = 0;
    this->width = 1600;
    this->height = 900;
    this->windowPlace = 0;
    sf::Vector2i winpos;
    winpos.x = 0;
    winpos.y = 0;
    //make window
    window.create(sf::VideoMode(this->width, this->height), "Undead Fighter", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(winpos);
    window.setFramerateLimit(60);
    //initialize the other screens/places/classes you go to from the menu.
    this->theGame = new Game(this->window);
    this->theSettings = new Settings(this->window);
    this->theScores = new Scores(this->window);
    this->theTest = new TestCases(this->window);
    //set fonts
    this->arial.loadFromFile("Fonts/arial.ttf");
    this->zagreb.loadFromFile("Fonts/zagreb_underground.ttf");
    //set titleText
    this->titleText.setFont(this->zagreb);
    this->titleText.setString("UNDEAD FIGHTER");
    this->titleText.setCharacterSize(130);
    this->titleText.setFillColor(sf::Color::Red);
    this->indent = this->width / 2 - this->titleText.getGlobalBounds().width / 2; //creates an indent so all options can start on the same X.
    this->titleText.setPosition(indent, 30.f);
    //set playText
    this->playText.setFont(this->zagreb);
    this->playText.setString("Play Game");
    this->playText.setCharacterSize(60);
    this->playText.setFillColor(sf::Color::Red);
    this->playText.setPosition(indent, this->height * 2 / 7);
    //set settingsText
    this->settingsText.setFont(this->zagreb);
    this->settingsText.setString("Settings");
    this->settingsText.setCharacterSize(60);
    this->settingsText.setFillColor(sf::Color::Red);
    this->settingsText.setPosition(indent, this->height * 3 / 7);
    //set scoresText
    this->scoresText.setFont(this->zagreb);
    this->scoresText.setString("Check Scores");
    this->scoresText.setCharacterSize(60);
    this->scoresText.setFillColor(sf::Color::Red);
    this->scoresText.setPosition(indent, this->height * 4 / 7);
    //set exitText
    this->exitText.setFont(this->zagreb);
    this->exitText.setString("Exit");
    this->exitText.setCharacterSize(60);
    this->exitText.setFillColor(sf::Color::Red);
    this->exitText.setPosition(indent, this->height * 5 / 7);
    //set tcases
     /// </summary>
    this->tCases.setFont(this->arial);
    this->tCases.setString("Test Cases (click 'U')");
    this->tCases.setCharacterSize(30);
    this->tCases.setFillColor(sf::Color::Red);
    this->tCases.setPosition(1200, this->height * 6 / 7);

}
Menu::~Menu(){

}
void Menu::fullLoop() {

     while (this->window.isOpen()) //the entirety of the game is inside thise while loop. All event loops and some clearing then displaying will be inide the funcitons
     {
        window.clear(); //clears off anything drawn on a previous window
        switch (this->windowPlace) {//sends us to the desired screen, at default this is mainMenu;
        case 0:
            this->mainMenu(); 
            break;
        case 1:
            this->playGame();
            break;
        case 2:
            this->settings();
            break;
        case 3:
            this->checkScores();   
            break;
        case 4:
            this->testCase();
            break;
        default:
            break;
        }
        window.display();
    }

	return;
}

int Menu::textClicked(sf::Text& text, float mouseX, float mouseY) {
    
    if ((text.getPosition().x < mouseX) && (mouseX < text.getPosition().x + text.getGlobalBounds().width)) { //if the mouse is between the left and right sides sides of the text.
        if ((text.getPosition().y < mouseY) && (mouseY < text.getPosition().y + text.getGlobalBounds().height)) { //if the mouse is between the top and bottom of the text
            return 1; //if both are true then the mouse must be inside the textbox, return true;
        }
    }
    return 0; //if the mouse is higher lower or further to the right or left return 0;
}

void Menu::mainMenu() {
    sf::Event event;
    while (window.pollEvent(event))//event looooop
    {   
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
            this->windowPlace = 4;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //runs a check to see if the mouse clicked on any of the buttons, depending on the button the windowPlace will move the screen to the game, settings or score.
        {
            if (textClicked(this->playText, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                this->windowPlace = 1;
            }
            if (textClicked(this->settingsText, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                this->windowPlace = 2;
            }
            if (textClicked(this->scoresText, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                this->windowPlace = 3;
            }
            if (textClicked(this->exitText, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                window.close();
            }
        }
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    //draws on the text that will be our title and our buttons
    window.draw(this->titleText);
    window.draw(this->playText);
    window.draw(this->settingsText);
    window.draw(this->scoresText);
    window.draw(this->exitText);
    window.draw(this->tCases);
}

void Menu::playGame() {
    while (this->windowPlace == 1) {  //has clear, event loop, and display inside 
        this->windowPlace = theGame->startGame(); 
    }
    delete theGame;  
    this->theGame = new Game(this->window); //resets theGame
}

void Menu::settings() {
    while (this->windowPlace == 2) {     //has clear, event loop, and display inside 
        this->windowPlace = theSettings->running();
    }
    delete theSettings;
    this->theSettings = new Settings(this->window); //resets settings
}
void Menu::checkScores() {
    while (this->windowPlace == 3) { //has clear, event loop, and display inside 
        this->windowPlace = theScores->running();
    }
    delete theScores; 
    this->theScores = new Scores(this->window); //resets theScores
}

void Menu::testCase() {
    while (this->windowPlace == 4) {
        this->windowPlace = theTest->startTestCases();
    }
    delete theTest;
    this->theTest = new TestCases(this->window);
}
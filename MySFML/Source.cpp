#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Menu.h"

int main() {
	Menu myMainMenu;
	myMainMenu.fullLoop();
	std::cout << "Progarm Finish";
	return 0;
}
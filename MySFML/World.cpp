#include "World.h"

 World::World() {
	 // laods and scales the texture for the background
	string imgPng = "Textures/backgroundVolcano.png";
	texture.loadFromFile(imgPng);
	sprite.setTexture(texture);
	Vector2f targetSize(1600, 900);
	sprite.setScale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);



}

void World::drawBackground(RenderWindow& window) {
	window.draw(sprite);
}
void World::drawBackground(RenderWindow& window, string str) {
	// displys texture for background:
	texture.loadFromFile(str);
	sprite.setTexture(texture);
	Vector2f targetSize(1600, 900);
	sprite.setScale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
	window.draw(sprite);
}
#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	player = new Player();
	player->setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(*player);
	player->render(window);
	endDraw();
}

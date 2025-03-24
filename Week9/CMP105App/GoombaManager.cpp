#include "GoombaManager.h"
#include <iostream>
using namespace std;
GoombaManager::GoombaManager(sf::Vector2u windowsize)
{
	sizeOfWindow = windowsize;
	spawnY = -100.f;
	texture.loadFromFile("gfx/Goomba.png");
	for (int i = 0; i < GOOMBA_COUNT; i++)
	{
		Goombas.push_back(Goomba());
		Goombas[i].setAlive(false);
		Goombas[i].setTexture(&texture);
		Goombas[i].setSize(sf::Vector2f(100, 100));
	}
	font.loadFromFile("font/arial.ttf");
	message.setFont(font);
	message.setCharacterSize(24);
	message.setPosition(300, 300);

}
GoombaManager::~GoombaManager()
{
}
void GoombaManager::update(float dt)
{
	timeSinceCountPrinted += dt;

	int numberOfGoombasAlive = 0;

	// call update on all ALIVE Goombas
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (Goombas[i].isAlive())
		{
			numberOfGoombasAlive++;
			Goombas[i].update(dt);
		}
	}

	message.setString(std::to_string(numberOfGoombasAlive));
}
void GoombaManager::spawn()
{
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (!Goombas[i].isAlive())
		{
			Goombas[i].setAlive(true);
			Goombas[i].setVelocity(0, 200);
			Goombas[i].setPosition(rand() % sizeOfWindow.x, spawnY);
			return;
		}
	}


}
void GoombaManager::deathCheck()
{
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (Goombas[i].isAlive())
		{
			if (Goombas[i].getPosition().y > sizeOfWindow.y)
			{
				Goombas[i].setAlive(false);
			}
		}
	}
}
void GoombaManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < Goombas.size(); i++)
	{
		if (Goombas[i].isAlive())
		{
			window->draw(Goombas[i]);
		}
	}
	window->draw(message);
}
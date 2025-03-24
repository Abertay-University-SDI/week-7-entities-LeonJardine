#include "BeachBallManager.h"
#include <iostream>
using namespace std;
BeachBallManager::BeachBallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(10, 10));
	}
}
BeachBallManager::~BeachBallManager()
{
}
void BeachBallManager::update(float dt)
{
	timeSinceCountPrinted += dt;

	int numberOfBallsAlive = 0;

	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			numberOfBallsAlive++;
			balls[i].update(dt);
		}
	}
	
	if (timeSinceCountPrinted > TIME_BETWEEN_PRINTING)
	{
		std::cout << numberOfBallsAlive << "\n";
		timeSinceCountPrinted = 0.f;
	}
}
void BeachBallManager::spawn(sf::Vector2f spawnPosition)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(300, 0);
			balls[i].setPosition(spawnPosition);
			return;
		}
	}



}
void BeachBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			
			if (balls[i].getPosition().x > 1200)
			{
				balls[i].setAlive(false);
			}
			
		}
	}
}
void BeachBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}
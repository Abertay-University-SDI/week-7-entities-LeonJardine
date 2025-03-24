
#pragma once
#include "Goomba.h"
#include <math.h>
#include <vector>
class GoombaManager
{
public:
	GoombaManager(sf::Vector2u windowsize);
	~GoombaManager();
	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
private:
	std::vector<Goomba> Goombas;
	float spawnY;;
	sf::Texture texture;
	sf::Font font;
	sf::Text message;
	float timeSinceCountPrinted = 0.f;
	sf::Vector2u sizeOfWindow;

	const float TIME_BETWEEN_PRINTING = 3.0f;
	const float GOOMBA_COUNT = 40;
};
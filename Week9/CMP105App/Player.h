#pragma once
#include "Framework/GameObject.h"
#include"BeachBallManager.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	void shoot();

	void update(float dt) override;
	void handleInput(float dt) override;
	void render(sf::RenderWindow* window);

	BeachBallManager* bulletManager;
	sf::Texture texture;
};


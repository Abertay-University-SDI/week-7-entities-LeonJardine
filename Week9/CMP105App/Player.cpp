#include "Player.h"

Player::Player()
{
	texture.loadFromFile("gfx/Goomba.png");
	setTexture(&texture);

	setPosition(50, 500);
	setSize(sf::Vector2f(80, 80));

	bulletManager = new BeachBallManager();
}

Player::~Player()
{
}

void Player::shoot()
{
}

void Player::update(float dt)
{
	move(velocity * dt);
	bulletManager->update(dt);
	bulletManager->deathCheck();
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity.y -= 0.05;
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y += 0.05;
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x -= 0.05;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x += 0.05;
	}
	if (input->isKeyDown(sf::Keyboard::R))
	{
		velocity = { 0, 0 };
		setPosition(50, 500);
	}
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		sf::Vector2f bulletOrigin = getPosition();
		bulletOrigin.x += getSize().x / 2;
		bulletOrigin.x += getSize().y / 2;
		bulletManager->spawn(bulletOrigin);
		input->setKeyUp(sf::Keyboard::Space);
	}
}

void Player::render(sf::RenderWindow* window)
{
	bulletManager->render(window);
}

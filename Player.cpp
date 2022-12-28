#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initSprite()
{
	this->texturePlayer.loadFromFile("../Data/Textures/ship.png");
	this->spritePlayer.setTexture(this->texturePlayer);
	this->spritePlayer.setScale(0.05, 0.05);
	this->spritePlayer.setPosition(100, 255);
	this->spritePlayer.rotate(90.f);
}	

Player::Player()
{
	this->initVariables();
	this->initSprite();
}

Player::~Player()
{
}

const sf::FloatRect Player::getBounds()
{
	return this->spritePlayer.getGlobalBounds();
}

sf::Vector2f Player::getPosition()
{
	return this->spritePlayer.getPosition();
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->spritePlayer.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->spritePlayer.setPosition(x, y);
}

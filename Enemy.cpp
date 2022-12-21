#include "Enemy.h"

void Enemy::initVariables()
{
}

void Enemy::initShapes(std::string name)
{
	this->textureEnemy = new sf::Texture();
	this->textureEnemy->loadFromFile("../Data/Textures/" +name +".png");
	this->spriteEnemy.setTexture(*this->textureEnemy);
	
	//this->spriteBat.setPosition(200, 100);
	//this->spriteBat.scale(1.2, 1.2);
}

Enemy::Enemy(std::string name)
{
	this->initVariables();
	this->initShapes(name);
}

Enemy::~Enemy()
{
}

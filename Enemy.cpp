#include "Enemy.h"

void Enemy::initShapes(std::string name) {

	this->textureEnemy = new sf::Texture();
	this->textureEnemy->loadFromFile("../Data/Textures/" + name + ".png");
	this->spriteEnemy.setTexture(*this->textureEnemy);
}

Enemy::Enemy(std::string name) {
	this->initVariables();
	this->initShapes(name);
}

sf::Sprite& Enemy::getSprite() {
	return this->spriteEnemy;
}

void Enemy::render(sf::RenderTarget* target) {
	target->draw(this->spriteEnemy);
}

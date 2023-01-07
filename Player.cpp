#include "Player.h"

void Player::initVariables() {
	this->movementSpeed = 10.f;
}

void Player::initSprite() {

	this->texturePlayer.loadFromFile("../Data/Textures/ship.png");
	this->spritePlayer.setTexture(this->texturePlayer);
	this->spritePlayer.setPosition(65, 255);
	this->spritePlayer.rotate(90.f);
}

Player::Player() {
	this->initVariables();
	this->initSprite();
}

const sf::FloatRect Player::getBounds() {
	return this->spritePlayer.getGlobalBounds();
}

sf::Vector2f Player::getPosition() {
	return this->spritePlayer.getPosition();
}

void Player::setPosition(const sf::Vector2f pos) {
	this->spritePlayer.setPosition(pos);
}

void Player::setPosition(const float x, const float y) {
	this->spritePlayer.setPosition(x, y);
}

void Player::move(float dir_X, float dir_Y) {
	this->spritePlayer.move(dir_X * this->movementSpeed, dir_Y * this->movementSpeed);
}

void Player::render(sf::RenderWindow* window) {
	window->draw(this->spritePlayer);
}

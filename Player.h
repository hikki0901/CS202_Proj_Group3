#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Player
{
private:
	sf::Texture texturePlayer;
	sf::Sprite spritePlayer;

	float movementSpeed;

	void initVariables();
	void initSprite();
public:
	Player();
	virtual ~Player();

	//acessors
	const sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	
	//modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	
	void move(float dir_X, float dir_Y);

	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
};

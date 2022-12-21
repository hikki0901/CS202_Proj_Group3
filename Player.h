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

};

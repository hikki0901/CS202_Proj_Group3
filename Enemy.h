#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

class Enemy {
private:
	
	sf::Texture* textureEnemy;
	sf::Sprite spriteEnemy;

	void initVariables() {};
	void initShapes(std::string name);

public:
	
	//cons & des
	Enemy(std::string name);
	virtual ~Enemy() {};

	//accesors
	sf::Sprite& getSprite();
	void render(sf::RenderTarget* target);
};

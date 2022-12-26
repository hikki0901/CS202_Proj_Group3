#pragma once
#include "Game.h"
#include "GameStateBase.h"

class GSMenu : public GameStateBase
{
private:

	Game* game;
	sf::RenderWindow* window;
	int currentState;
	//loadgame
	int velocityLoadGame;
	sf::Vector2f positionPlayerLoadGame;
	//text file
	std::ifstream fin;
	std::ofstream fout;
	//mouse pos
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::Texture* textureBackground;
	sf::Sprite* spriteBackGround;

	sf::Texture* texture1;
	sf::Sprite* shape1;

	sf::Texture* texture2;
	sf::Sprite* shape2;

	sf::Texture* texture3;
	sf::Sprite* shape3;

	sf::Texture* texture4;
	sf::Sprite* shape4;

	sf::Texture* texture5;
	sf::Sprite* shape5;

	sf::Font font;
	sf::Text text;

	sf::Text textPlay;
	sf::Text saveGame;

	void initFont();
	void initText();
}

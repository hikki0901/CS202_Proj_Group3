#include "GSMenu.h"

void GSMenu::initFont()
{
	font.loadFromFile("../Data/Fonts/ARCADE.TTF");
}

void GSMenu::initText()
{
	text.setFont(font);	
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(65);
	text.setPosition(200, 150);
	text.setString("Crossing the forest ");
}

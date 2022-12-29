#include "Game.h"
void Game::initVariables()
{
	player = new Player();
	this->continueGame = false;
	this->level = 1;
	this->difficulty = 1;
	this->velocity = 2.f;
	this->spawnTimerMax1 = static_cast<float>(rand()%50 + 20);
	this->spawnTimer1 = 0;
	this->spawnTimerMax2 = static_cast<float>(rand() % 50 + 20);
	this->spawnTimer2 = 0;
	this->spawnTimerMax3 = static_cast<float>(rand() % 50 + 20);
	this->spawnTimer3 = 0;
	this->spawnTimerMax4 = static_cast<float>(rand() % 50 + 20);
	this->spawnTimer4 = 0;
	this->type1 = 0;
	this->type2 = 0;
	this->type3 = 0;
	this->endGame = false;
}

void Game::initWindow()
{
	this->videomode.width = 928;
	this->videomode.height = 580;

	this->window = new sf::RenderWindow(this->videomode, "Crossing", sf::Style::Default);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initBackground()
{
	this->textureBackground.loadFromFile("../Data/Textures/Background.png");
	this->spriteBackGround.setTexture(this->textureBackground);
	this->spriteBackGround.setOrigin((sf::Vector2f)this->textureBackground.getSize() / 2.f);
	this->spriteBackGround.setPosition(this->videomode.width / 2,
		this->videomode.height - this->textureBackground.getSize().y/ 2);
}

void Game::initEnemyColumn()
{

	// line 1
	Enemy* enemy = new Enemy("Bat");
	enemy->getSprite().setPosition(sf::Vector2f(200, 170));
	this->enemyLine1.push_back(enemy);
	this->enemyTotal.push_back(enemy);

	Enemy* enemy1 = new Enemy("Bat");
	enemy1->getSprite().setPosition(sf::Vector2f(200, 350));
	this->enemyLine1.push_back(enemy1);
	this->enemyTotal.push_back(enemy1);

	Enemy* enemy0 = new Enemy("Bat");
	enemy0->getSprite().setPosition(sf::Vector2f(200, 530));
	this->enemyLine1.push_back(enemy0);
	this->enemyTotal.push_back(enemy0);

	// line 2
	Enemy* enemy2 = new Enemy("Boss2");
	enemy2->getSprite().setPosition(sf::Vector2f(320, 70));
	enemy2->getSprite().setScale(0.4, 0.4);
	this->enemyLine2.push_back(enemy2);
	this->enemyTotal.push_back(enemy2);

	Enemy* enemy3 = new Enemy("Boss2");
	enemy3->getSprite().setPosition(sf::Vector2f(320, 210));
	enemy3->getSprite().setScale(0.4, 0.4);
	this->enemyLine2.push_back(enemy3);
	this->enemyTotal.push_back(enemy3);

	Enemy* enemy4 = new Enemy("Boss2");
	enemy4->getSprite().setPosition(sf::Vector2f(320, 350));
	enemy4->getSprite().setScale(0.4, 0.4);
	this->enemyLine2.push_back(enemy4);
	this->enemyTotal.push_back(enemy4);

	// line 3
	Enemy* enemy5 = new Enemy("Boss1");
	enemy5->getSprite().setPosition(sf::Vector2f(570, 70));
	enemy5->getSprite().setScale(0.5, 0.5);
	this->enemyLine3.push_back(enemy5);
	this->enemyTotal.push_back(enemy5);

	Enemy* enemy6 = new Enemy("Boss1");
	enemy6->getSprite().setPosition(sf::Vector2f(570, 210));
	enemy6->getSprite().setScale(0.5, 0.5);
	this->enemyLine3.push_back(enemy6);
	this->enemyTotal.push_back(enemy6);

	Enemy* enemy7 = new Enemy("Boss1");
	enemy7->getSprite().setPosition(sf::Vector2f(570, 350));
	enemy7->getSprite().setScale(0.5, 0.5);
	this->enemyLine3.push_back(enemy7);
	this->enemyTotal.push_back(enemy7);

	// line 4
	Enemy* enemy8 = new Enemy("Boss2");
	enemy8->getSprite().setPosition(sf::Vector2f(720, 50));
	enemy8->getSprite().setScale(0.4, 0.4);
	this->enemyLine4.push_back(enemy8);
	this->enemyTotal.push_back(enemy8);

	Enemy* enemy9 = new Enemy("Boss2");
	enemy9->getSprite().setPosition(sf::Vector2f(720, 190));
	enemy9->getSprite().setScale(0.4, 0.4);
	this->enemyLine4.push_back(enemy9);
	this->enemyTotal.push_back(enemy9);

	Enemy* enemy10 = new Enemy("Boss2");
	enemy10->getSprite().setPosition(sf::Vector2f(720, 330));
	enemy10->getSprite().setScale(0.4, 0.4);
	this->enemyLine4.push_back(enemy10);
	this->enemyTotal.push_back(enemy10);

	Enemy* enemy11 = new Enemy("Boss2");
	enemy11->getSprite().setPosition(sf::Vector2f(720, 470));
	enemy11->getSprite().setScale(0.4, 0.4);
	this->enemyLine4.push_back(enemy11);
	this->enemyTotal.push_back(enemy11);
}

void Game::initFont()
{
	font.loadFromFile("../Data/Fonts/ARCADE.TTF");
}

void Game::initText()
{
	//play
	textPlay.setFont(font);
	textPlay.setFillColor(sf::Color::White);
	textPlay.setCharacterSize(35);
	textPlay.setPosition(20, 30);
	textPlay.setString("Level :  ");
	std::stringstream ss;
	ss << "Level : " << this->velocity/2;
	this->textPlay.setString(ss.str());
}

Game::Game()
{
	initVariables();
	initWindow();
	initBackground();
	initEnemyColumn();
	initFont();
	initText();
}

Game::~Game()
{
	delete window;
}

void Game::setEndGame(bool x)
{
	this->endGame = x;
}

void Game::setContinueGame(bool x)
{
	this->continueGame = x;
}

void Game::setPositionPlayer(float x, float y)
{
	this->player->setPosition(x, y);
}

void Game::setDifficulty(int x)
{
	this->difficulty = x;
}

void Game::setVelocity(int x)
{
	this->velocity = x;
}






void Game::updateDifficulty()
{
	if (this->player->getPosition().x >= 920)
	{
		this->player->setPosition(100, 255);
		this->velocity += 2;
		std::cout << this->velocity / 2 << "\n";
	}
	std::stringstream ss;
	ss << "Level : " << this->velocity / 2;
	this->textPlay.setString(ss.str());
}

void Game::updateCollisionEnemy()
{
	for (int i = 0; i < enemyTotal.size() && this->endGame == false; i++)
	{
		if (this->enemyTotal[i]->getSprite().getGlobalBounds().
			intersects(this->player->getBounds()))
		{
			this->endGame = true;
			this->continueGame = false;
		}
	}
}
#include "Game.h"

void Game::initVariables()
{
	player = new Player();
	this->continueGame = false;
	this->level = 1;
	this->current = 1;
	this->difficulty = 1;
	this->velocity = 2.f;

	this->spawnTimerMax1 = static_cast<float>(rand() % 50 + 20);
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
	this->type4 = 0;

	this->endGame = false;
}

void Game::initWindow() {

	this->videomode.width = 928;
	this->videomode.height = 580;
	this->window = new sf::RenderWindow(this->videomode, "Crossing", sf::Style::Default);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initBackground() {

	this->textureBackground.loadFromFile("../Data/Textures/Background.png");
	this->spriteBackGround.setTexture(this->textureBackground);
	this->spriteBackGround.setOrigin((sf::Vector2f)this->textureBackground.getSize() / 2.f);
	this->spriteBackGround.setPosition(this->videomode.width / 2,
	this->videomode.height - this->textureBackground.getSize().y/ 2);
}

void Game::initEnemyColumn()
{
	srand(time(0));
	// line 1
	Enemy* enemy = new Enemy(std::to_string(rand() % 10 + 1));
	enemy->getSprite().setPosition(sf::Vector2f(230, 170));
	this->enemyLine1.push_back(enemy);
	this->enemyTotal.push_back(enemy);

	Enemy* enemy1 = new Enemy(std::to_string(rand() % 10 + 1));
	enemy1->getSprite().setPosition(sf::Vector2f(230, 350));
	this->enemyLine1.push_back(enemy1);
	this->enemyTotal.push_back(enemy1);

	Enemy* enemy0 = new Enemy(std::to_string(rand() % 10 + 1));
	enemy0->getSprite().setPosition(sf::Vector2f(230, 530));
	this->enemyLine1.push_back(enemy0);
	this->enemyTotal.push_back(enemy0);

	// line 2
	Enemy* enemy2 = new Enemy(std::to_string(rand() % 10 + 11));
	enemy2->getSprite().setPosition(sf::Vector2f(370, 70));
	this->enemyLine2.push_back(enemy2);
	this->enemyTotal.push_back(enemy2);

	Enemy* enemy3 = new Enemy(std::to_string(rand() % 10 + 11));
	enemy3->getSprite().setPosition(sf::Vector2f(370, 270));
	this->enemyLine2.push_back(enemy3);
	this->enemyTotal.push_back(enemy3);

	Enemy* enemy4 = new Enemy(std::to_string(rand() % 10 + 11));
	enemy4->getSprite().setPosition(sf::Vector2f(370, 470));
	this->enemyLine2.push_back(enemy4);
	this->enemyTotal.push_back(enemy4);

	// line 3
	Enemy* enemy5 = new Enemy(std::to_string(rand() % 10 + 1));
	enemy5->getSprite().setPosition(sf::Vector2f(530, 40));
	this->enemyLine3.push_back(enemy5);
	this->enemyTotal.push_back(enemy5);

	Enemy* enemy6 = new Enemy(std::to_string(rand() % 10 + 1));
	enemy6->getSprite().setPosition(sf::Vector2f(530, 230));
	this->enemyLine3.push_back(enemy6);
	this->enemyTotal.push_back(enemy6);

	Enemy* enemy7 = new Enemy(std::to_string(rand() % 10 + 1));
	enemy7->getSprite().setPosition(sf::Vector2f(530, 420));
	this->enemyLine3.push_back(enemy7);
	this->enemyTotal.push_back(enemy7);

	// line 4
	Enemy* enemy8 = new Enemy(std::to_string(rand() % 10 + 11));
	enemy8->getSprite().setPosition(sf::Vector2f(680, 50));
	this->enemyLine4.push_back(enemy8);
	this->enemyTotal.push_back(enemy8);

	Enemy* enemy9 = new Enemy(std::to_string(rand() % 10 + 11));
	enemy9->getSprite().setPosition(sf::Vector2f(680, 230));
	this->enemyLine4.push_back(enemy9);
	this->enemyTotal.push_back(enemy9);

	Enemy* enemy10 = new Enemy(std::to_string(rand() % 10 + 11));
	enemy10->getSprite().setPosition(sf::Vector2f(680, 410));
	this->enemyLine4.push_back(enemy10);
	this->enemyTotal.push_back(enemy10);

	Enemy* enemy11 = new Enemy(std::to_string(rand() % 10 + 11));
	enemy11->getSprite().setPosition(sf::Vector2f(680, 590));
	this->enemyLine4.push_back(enemy11);
	this->enemyTotal.push_back(enemy11);
}

void Game::clearEnemyColumn()
{
	delete this->enemyLine1[0];
	delete this->enemyLine1[1];
	delete this->enemyLine1[2];

	delete this->enemyLine2[0];
	delete this->enemyLine2[1];
	delete this->enemyLine2[2];

	delete this->enemyLine3[0];
	delete this->enemyLine3[1];
	delete this->enemyLine3[2];

	delete this->enemyLine4[0];
	delete this->enemyLine4[1];
	delete this->enemyLine4[2];
	delete this->enemyLine4[3];

	this->enemyLine1.clear();
	this->enemyLine2.clear();
	this->enemyLine3.clear();
	this->enemyLine4.clear();
	this->enemyTotal.clear();
}

void Game::initFont() {
	font.loadFromFile("../Data/Fonts/ARCADE.TTF");
}

void Game::initText() {

	textPlay.setFont(font);
	textPlay.setFillColor(sf::Color::White);
	textPlay.setCharacterSize(35);
	textPlay.setPosition(20, 30);
	textPlay.setString("Level :  ");
	std::stringstream ss;
	ss << "Level : " << this->velocity/2;
	this->textPlay.setString(ss.str());

	guide1.setFont(font);
	guide1.setFillColor(sf::Color::White);
	guide1.setCharacterSize(20);
	guide1.setPosition(20, 530);
	guide1.setString("T to save current game");

	guide2.setFont(font);
	guide2.setFillColor(sf::Color::White);
	guide2.setCharacterSize(20);
	guide2.setPosition(20, 550);
	guide2.setString("Arrow key to control the ship");

	guide3.setFont(font);
	guide3.setFillColor(sf::Color::White);
	guide3.setCharacterSize(20);
	guide3.setPosition(20, 490);
	guide3.setString("Esc to exit the game");

	guide4.setFont(font);
	guide4.setFillColor(sf::Color::White);
	guide4.setCharacterSize(20);
	guide4.setPosition(20, 510);
	guide4.setString("P to pause the game");
}

Game::Game() {

	initVariables();
	initWindow();
	initBackground();
	initEnemyColumn();
	initFont();
	initText();
}

void Game::saveGame() {

	this->window->clear();
	this->renderBackground();

	sf::Text textSave1;
	textSave1.setFont(this->font);
	textSave1.setCharacterSize(65);
	textSave1.setFillColor(sf::Color::White);
	textSave1.setPosition(200, 150);

	std::stringstream ss1;
	ss1 << "\nSAVE GAME SUCCESSFULLY " << "\n" << "PRESS SPACE TO CONTINUE";
	textSave1.setString(ss1.str());
	this->window->draw(textSave1);
	this->window->display();
}

void Game::pauseGame() {

	this->window->clear();
	this->renderBackground();

	sf::Text textSave2;
	textSave2.setFont(this->font);
	textSave2.setCharacterSize(65);
	textSave2.setFillColor(sf::Color::White);
	textSave2.setPosition(200, 150);

	std::stringstream ss2;
	ss2 << "\n    YOUR GAME IS PAUSED " << "\n" << "PRESS SPACE TO CONTINUE";
	textSave2.setString(ss2.str());
	this->window->draw(textSave2);
	this->window->display();
}

sf::RenderWindow* Game::getWindow() { return this->window; }
sf::Vector2f Game::getPositionPlayer() { return player->getPosition(); }

bool Game::getEndGame() { return this->endGame; }
bool Game::getContinueGame() { return this->continueGame; }

int Game::getDiffculty() { return this->difficulty; }
int Game::getVelocity() { return this->velocity; }

void Game::setEndGame(bool x) {

	this->endGame = x;
	for (int i = 0; i < 9; i++)
		if (this->velocity / 2 > leaderboard[i]) {
			leaderboard.insert(leaderboard.begin() + i, this->velocity / 2);
			break;
		}

	std::ofstream fout;
	fout.open("leaderboard.txt");
	for (int i = 0; i < 9; i++)
		fout << leaderboard[i] << "\n";
}

void Game::setContinueGame(bool x) { this->continueGame = x; }
void Game::setPositionPlayer(float x, float y) { this->player->setPosition(x, y); }
void Game::setDifficulty(int x) { this->difficulty = x; }
void Game::setVelocity(int x) { this->velocity = x; }

void Game::pollEvents() {

	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
		}
	}
}

void Game::loadLeaderboard() {

	std::ifstream fin;
	fin.open("leaderboard.txt");
	for (int i = 0; i < 10; i++) {
		int tmp; fin >> tmp;
		leaderboard.push_back(tmp);
	}
	fin.close();
}

void Game::showLeaderboard() {

	this->window->clear();
	this->renderBackground();

	sf::Text textSave2;
	textSave2.setFont(this->font);
	textSave2.setCharacterSize(80);
	textSave2.setFillColor(sf::Color::White);

	textSave2.setPosition(280, 50);
	{
		std::stringstream ss2;
		ss2 << "LEADERBOARD";
		textSave2.setString(ss2.str());
		this->window->draw(textSave2);
	}

	textSave2.setPosition(110, 450);
	{
		std::stringstream ss2;
		ss2 << "PRESS SPACE TO CONTINUE";
		textSave2.setString(ss2.str());
		this->window->draw(textSave2);
	}

	textSave2.setCharacterSize(40);
	for (int i = 0; i < 9; i++) {
		textSave2.setPosition(280, 130 + i * 35);
		{
			std::stringstream ss2;
			if (leaderboard[i] != 0) ss2 << i + 1 << " ____________________ Level " << leaderboard[i];
			else ss2 << i + 1 << " ____________________________";
			textSave2.setString(ss2.str());
			this->window->draw(textSave2);
		}
	}

	this->window->display();
}

void Game::updateInput() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->player->move(0.f, 1.f);
}

void Game::updateCollisionWindow() {

	float L = this->player->getBounds().left;
	float T = this->player->getBounds().top;

	float W = this->player->getBounds().width;
	float H = this->player->getBounds().height;

	unsigned int X = this->window->getSize().x;
	unsigned int Y = this->window->getSize().y;

	// left + right world collision
	if (L < 0.f) this->player->setPosition(0.f + W, T);
	else if (L + W >= X) this->player->setPosition(X, T);

	// top + bottom world collision
	if (T < 0.f) this->player->setPosition(L + W, 0.f);
	else if (T + H >= Y) this->player->setPosition(L + W, Y - H);
}

void Game::updateDifficulty()
{

	if (this->player->getPosition().x >= 920)
	{
		this->player->setPosition(100, 255);
		this->velocity += 2;
		this->level = this->velocity / 2;
	}
	this->textPlay.setCharacterSize(30);
	this->textPlay.setPosition(10, 10);
	std::stringstream ss;
	ss << "LEVEL : " << this->velocity / 2 << "\nPERSONAL BEST: LEVEL " << this->leaderboard[0];;
	this->textPlay.setString(ss.str());
}

void Game::updateCollisionEnemy() {

	for (int i = 0; i < enemyTotal.size() && this->endGame == false; i++)
		if (this->enemyTotal[i]->getSprite().getGlobalBounds().intersects(this->player->getBounds())) {
			this->endGame = true;
			this->continueGame = false;
		}
}

void Game::updateEnemies1()
{
	if (this->spawnTimer1 < this->spawnTimerMax1) this->spawnTimer1 += 0.3;
	else if(type1 != 2)
	{
		this->spawnTimer1 = 0.f;
		this->spawnTimerMax1 = static_cast<float>(rand() % 50 + 30);
		type1 = 2;
	}
	if (type1 == 0)
	{
		for (int i = 0; i < enemyLine1.size(); i++)
		{
			this->enemyLine1[i]->getSprite().move(0, -velocity);
		}
		if (this->enemyLine1[0]->getSprite().getGlobalBounds().top <= 0) type1 = 1;
	}
	else if (type1 == 1)
	{
		for (int i = 0; i < enemyLine1.size(); i++)
		{
			this->enemyLine1[i]->getSprite().move(0, velocity);
		}
		if (this->enemyLine1[2]->getSprite().getGlobalBounds().top
			+ this->enemyLine1[2]->getSprite().getGlobalBounds().height
		>  this->videomode.height) type1 = 0;
	}
	if (type1 == 2)
	{
		if (this->spawnTimer1 >= this->spawnTimerMax1)
		{
			type1 = 0;
			this->spawnTimer1 = 0.f;
			this->spawnTimerMax1 = static_cast<float>(rand() % 50 + 100);
		}
	}

}

void Game::updateEnemies2()
{
	if (this->spawnTimer2 < this->spawnTimerMax2) this->spawnTimer2 += 0.3;
	else if (type2 != 2)
	{
		this->spawnTimer2 = 0.f;
		this->spawnTimerMax2 = static_cast<float>(rand() % 50 + 30);
		type2 = 2;
	}
	if (type2 == 0)
	{
		for (int i = 0; i < enemyLine2.size(); i++)
		{
			this->enemyLine2[i]->getSprite().move(0, -velocity);
		}
		if (this->enemyLine2[0]->getSprite().getGlobalBounds().top <= 0) type2 = 1;
	}
	else if (type2 == 1)
	{
		for (int i = 0; i < enemyLine2.size(); i++)
		{
			this->enemyLine2[i]->getSprite().move(0, velocity);
		}
		if (this->enemyLine2[2]->getSprite().getGlobalBounds().top
			+ this->enemyLine2[2]->getSprite().getGlobalBounds().height
		> this->videomode.height) type2 = 0;
	}
	if (type2 == 2)
	{
		if (this->spawnTimer2 >= this->spawnTimerMax2)
		{
			type2 = 0;
			this->spawnTimer2 = 0.f;
			this->spawnTimerMax2 = static_cast<float>(rand() % 50 + 100);
		}
	}
}

void Game::updateEnemies3()
{
	if (this->spawnTimer3 < this->spawnTimerMax3) this->spawnTimer3 += 0.3;
	else if (type3 != 2)
	{
		this->spawnTimer3 = 0.f;
		this->spawnTimerMax3 = static_cast<float>(rand() % 50 + 30);
		type3 = 2;
	}
	if (type3 == 0)
	{
		for (int i = 0; i < enemyLine3.size(); i++)
		{
			this->enemyLine3[i]->getSprite().move(0, -velocity);
		}
		if (this->enemyLine3[0]->getSprite().getGlobalBounds().top <= 0) type3 = 1;
	}
	else if (type3 == 1)
	{
		for (int i = 0; i < enemyLine3.size(); i++)
		{
			this->enemyLine3[i]->getSprite().move(0, velocity);
		}
		if (this->enemyLine3[2]->getSprite().getGlobalBounds().top
			+ this->enemyLine3[2]->getSprite().getGlobalBounds().height
		> this->videomode.height) type3 = 0;
	}

	if (type3 == 2)
	{
		if (this->spawnTimer3 >= this->spawnTimerMax3)
		{
			type3 = 0;
			this->spawnTimer3 = 0.f;
			this->spawnTimerMax3 = static_cast<float>(rand() % 50 + 100);
		}
	}
}

void Game::updateEnemies4()
{
	if (this->spawnTimer4 < this->spawnTimerMax4) this->spawnTimer4 += 0.3;
	else if (type4 != 2)
	{
		this->spawnTimer4 = 0.f;
		this->spawnTimerMax4 = static_cast<float>(rand() % 50 + 30);
		type4 = 2;
	}
	if (type4 == 0)
	{
		for (int i = 0; i < enemyLine4.size(); i++)
		{
			this->enemyLine4[i]->getSprite().move(0, -velocity);
		}
		if (this->enemyLine4[1]->getSprite().getGlobalBounds().top <= 0) type4 = 1;
	}
	else if (type4 == 1)
	{
		for (int i = 0; i < enemyLine4.size(); i++)
		{
			this->enemyLine4[i]->getSprite().move(0, velocity);
		}
		if (this->enemyLine4[2]->getSprite().getGlobalBounds().top
			+ this->enemyLine4[2]->getSprite().getGlobalBounds().height
		> this->videomode.height) type4 = 0;
	}
	if (type4 == 2)
	{
		if (this->spawnTimer4 >= this->spawnTimerMax4)
		{
			type4 = 0;
			this->spawnTimer4 = 0.f;
			this->spawnTimerMax4 = static_cast<float>(rand() % 50 + 100);
		}
	}
}

void Game::update()
{
	if (this->current != this->level)
	{
		this->clearEnemyColumn();
		this->initEnemyColumn();
		this->current = this->level;
	}
	this->updateInput();
	this->updateCollisionWindow();
	this->updateEnemies1();
	this->updateEnemies2();
	this->updateEnemies3();
	this->updateEnemies4();
	this->updateCollisionEnemy();
	this->updateDifficulty();
	this->render();
}

void Game::renderBackground() {
	this->window->draw(this->spriteBackGround);
}

void Game::renderEnemies() {

	for (int i = 0; i < this->enemyLine1.size(); i++)
		this->enemyLine1[i]->render(this->window);
	for (int i = 0; i < this->enemyLine2.size(); i++)
		this->enemyLine2[i]->render(this->window);
	for (int i = 0; i < this->enemyLine3.size(); i++)
		this->enemyLine3[i]->render(this->window);
	for (int i = 0; i < this->enemyLine4.size(); i++)
		this->enemyLine4[i]->render(this->window);
}

void Game::render() {

	window->clear();

	this->renderBackground();
	this->player->render(this->window);
	this->renderEnemies();

	this->window->draw(textPlay);
	this->window->draw(guide1);
	this->window->draw(guide2);
	this->window->draw(guide3);
	this->window->draw(guide4);

	window->display();
}

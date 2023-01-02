#pragma once
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <ctime>
#include <vector>
#include<sstream>
#include <string>
#include <fstream>

class Game 
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;
	
	int difficulty;
	int level;
	
	//background
	sf::Texture textureBackground;
	sf::Sprite spriteBackGround;
	
	//player
	Player* player;

	//leaderboard
	std::vector <int> leaderboard;

	//Enemy
	std::vector <Enemy*> enemyTotal;
	std::vector <Enemy*> enemyLine1;
	std::vector <Enemy*> enemyLine2;
	std::vector <Enemy*> enemyLine3;
	std::vector <Enemy*> enemyLine4;
	
	float spawnTimerMax1;
	float spawnTimer1;
	float spawnTimerMax2;
	float spawnTimer2;
	float spawnTimerMax3;
	float spawnTimer3;
	float spawnTimerMax4;
	float spawnTimer4;
	
	int type1;
	int type2;
	int type3;
	int type4;

	sf::Font font;
	sf::Text textPlay;
	
	sf::Text guide1;
	sf::Text guide2;
	sf::Text guide3;
	sf::Text guide4;
 
	float velocity;
	bool endGame;
	void initVariables();
	void initWindow();
	void initBackground();
	void initEnemyColumn();
	void initFont();
	void initText();
public:
	Game();
	virtual ~Game();

	void saveGame();
	void pauseGame();
	
	//accessors
	sf::RenderWindow* getWindow();
	bool getEndGame();
	bool getContinueGame();
	int getDiffculty();
	int getVelocity();
	bool continueGame;
	sf::Vector2f getPositionPlayer();
	
	//modifiers
	void setEndGame(bool x);
	void setContinueGame(bool x);
	void setPositionPlayer(float x, float y);
	void setDifficulty(int x);
	void setVelocity(int x);
	void loadLeaderboard();
	void showLeaderboard();
	
	void pollEvents();
	void updateInput();
	void updateCollisionWindow();
	void updateEnemies1();
	void updateEnemies2();
	void updateEnemies3();
	void updateEnemies4();
	void updateDifficulty();
	void updateCollisionEnemy();
	void update();

	void renderBackground();
	void renderEnemies();
	void render();
};

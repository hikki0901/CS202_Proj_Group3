#include "GSMenu.h"

void GSMenu::initFont() {
	font.loadFromFile("../Data/Fonts/ARCADE.TTF");
}

void GSMenu::initText() {
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(80);
	text.setPosition(260, 100);
	text.setString("CROSSING ROAD");
}

GSMenu::GSMenu() {

	this->currentState = StateTypes::MENU;
	game = new Game();
	this->window = game->getWindow();

	this->Init();
	this->initFont();
	this->initText();
}

int GSMenu::getType() {
	return this->currentState;
}

void GSMenu::run() {

	if (!music.openFromFile("../Data/Music/music.wav")) return;

	music.play();
	music.setLoop(true);
	game->loadLeaderboard();

	while (this->window->isOpen()) {
		game->pollEvents();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) || this->currentState == StateTypes::SAVEGAME) {
			game->saveGame();
			this->velocityLoadGame = game->getVelocity();
			this->positionPlayerLoadGame = game->getPositionPlayer();

			fout.open("loadgame.txt");
			fout << this->velocityLoadGame << "\n" << this->positionPlayerLoadGame.x
				<< "\n" << this->positionPlayerLoadGame.y;
			fout.close();

			this->currentState = StateTypes::SAVEGAME;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				this->currentState = StateTypes::PLAY;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) || this->currentState == StateTypes::PAUSEGAME) {
			game->pauseGame();
			this->currentState = StateTypes::PAUSEGAME;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				this->currentState = StateTypes::PLAY;
		} else if (this->currentState == StateTypes::MENU) {
			this->Render();
			this->Update();

			if (game->getEndGame() == true) {
				game->setPositionPlayer(65, 255);
				game->setEndGame(false);
				game->setVelocity(2);
			}
		} else if (this->currentState == StateTypes::PLAY) {
			if (game->getEndGame() == false) game->update();
			else {
				game->gameOver();
				this->currentState = StateTypes::GAMEOVER;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					this->currentState = StateTypes::MENU;
			}
		} else if (this->currentState == StateTypes::LOADGAME) {
			fin.open("loadgame.txt", std::ios::in);
			fin >> this->velocityLoadGame >> positionPlayerLoadGame.x
				>> positionPlayerLoadGame.y;
			fin.close();

			game->setPositionPlayer(positionPlayerLoadGame.x, positionPlayerLoadGame.y);
			game->setVelocity(this->velocityLoadGame);
			this->currentState = StateTypes::PLAY;
		} else if (this->currentState == StateTypes::SETTING) {
			if (music.getStatus() == 2) {
				music.pause();
				this->texture4->loadFromFile("../Data/btn/sound_off.png");
				this->shape4->setTexture(*texture4);
				this->shape4->setScale(0.4, 0.4);
				this->shape4->setPosition(430 + 928 / 12, 460);
				this->currentState = StateTypes::MENU;
			} else {
				music.play();
				this->texture4->loadFromFile("../Data/btn/sound.png");
				this->shape4->setTexture(*texture4);
				this->shape4->setScale(0.4, 0.4);
				this->shape4->setPosition(430 + 928 / 12, 460);
				this->currentState = StateTypes::MENU;
			}
		} else if (this->currentState == StateTypes::HIGHSCORE) {
			game->showLeaderboard();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				this->currentState = StateTypes::MENU;
		} else if ((this->game->getEndGame() == true) || (this->currentState == StateTypes::GAMEOVER)) {
			game->gameOver();
			this->currentState = StateTypes::GAMEOVER;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				this->currentState = StateTypes::MENU;
		}
	}
}

void GSMenu::Init() {

	this->mousePosWindow = sf::Mouse::getPosition(*window);

	textureBackground = new sf::Texture();
	spriteBackGround = new sf::Sprite();
	shape1 = new sf::Sprite();
	texture1 = new sf::Texture();
	shape2 = new sf::Sprite();
	texture2 = new sf::Texture();
	shape3 = new sf::Sprite();
	texture3 = new sf::Texture();
	shape4 = new sf::Sprite();
	texture4 = new sf::Texture();
	shape5 = new sf::Sprite();
	texture5 = new sf::Texture();

	this->textureBackground->loadFromFile("../Data/Textures/Background.png");
	this->spriteBackGround->setTexture(*this->textureBackground);
	this->spriteBackGround->setOrigin((sf::Vector2f)this->textureBackground->getSize() / 2.f);
	this->spriteBackGround->setPosition(928 / 2,
		580 - this->textureBackground->getSize().y / 2);

	//play
	this->texture1->loadFromFile("../Data/btn/play.png");
	this->shape1->setTexture(*texture1);
	this->shape1->setPosition(395, 250);
	this->shape1->setScale(0.7, 0.7);

	//load game
	this->texture2->loadFromFile("../Data/btn/ok.png");
	this->shape2->setTexture(*texture2);
	this->shape2->setScale(0.4, 0.4);
	this->shape2->setPosition(430 - 928 / 4, 460);

	//highscore game
	this->texture3->loadFromFile("../Data/btn/prize.png");
	this->shape3->setTexture(*texture3);
	this->shape3->setScale(0.4, 0.4);
	this->shape3->setPosition(430 - 928 / 12, 460);

	//setting game
	this->texture4->loadFromFile("../Data/btn/sound.png");
	this->shape4->setTexture(*texture4);
	this->shape4->setScale(0.4, 0.4);
	this->shape4->setPosition(430 + 928 / 12, 460);

	//exit game
	this->texture5->loadFromFile("../Data/btn/close.png");
	this->shape5->setTexture(*texture5);
	this->shape5->setScale(0.4, 0.4);
	this->shape5->setPosition(430 + 928 / 4, 460);
}

void GSMenu::Update() {

	if (this->shape1->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->currentState = StateTypes::PLAY;

	if (this->shape2->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->currentState = StateTypes::LOADGAME;

	if (this->shape3->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->currentState = StateTypes::HIGHSCORE;

	if (this->shape4->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->currentState = StateTypes::SETTING;

	if (this->shape5->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->window->close();
}

void GSMenu::Render() {

	window->clear();
	window->draw(*this->spriteBackGround);
	window->draw(*this->shape1);
	window->draw(*this->shape2);
	window->draw(*this->shape3);
	window->draw(*this->shape4);
	window->draw(*this->shape5);
	window->draw(text);
	window->display();
}

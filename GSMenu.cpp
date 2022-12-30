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

GSMenu::GSMenu()
{
	this->currentState = StateTypes::MENU;
	game = new Game();
	this->window = game->getWindow();
	this->Init();
	this->initFont();
	this->initText();
}
GSMenu::~GSMenu()
{
}

int GSMenu::getType()
{
	return this->currentState;
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{

}

void GSMenu::Resume()
{
}

void GSMenu::run()
{
	if (!music.openFromFile("../Data/Music/music.wav"))
		return; // error
	music.play();
	music.setLoop(true);
	while (this->window->isOpen())
	{
		game->pollEvents();

		//std::cout <<  "STATE: " << this->currentState << " "
		//	<< game->getEndGame() << "\n";
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) ||
			this->currentState == StateTypes::SAVEGAME)
		{
			// save game
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
		}
		else if (this->currentState == StateTypes::MENU)
		{
			this->Render();
			this->Update();
			if (game->getEndGame() == true)
			{
				game->setPositionPlayer(100, 255);
				game->setEndGame(false);
				game->setVelocity(2);
				//game->setContinueGame(true);
			}
		}
		else if (this->currentState == StateTypes::PLAY)
		{
			if (game->getEndGame() == false)
			{
				game->update();
			}
			else
			{
				std::cout << "CHUYEN DOI TRANG THAI \n";
				this->currentState = StateTypes::MENU;
			}

			//std::cout << game->getEndGame() << "\n";
		}
		else if (this->currentState == StateTypes::LOADGAME)
		{
			fin.open("loadgame.txt", std::ios::in);
			fin >> this->velocityLoadGame >> positionPlayerLoadGame.x
				>> positionPlayerLoadGame.y;
			fin.close();
			game->setPositionPlayer(positionPlayerLoadGame.x, positionPlayerLoadGame.y);
			game->setVelocity(this->velocityLoadGame);
			this->currentState = StateTypes::PLAY;
		}
	}
}

void GSMenu::Init()
{
	this->mousePosWindow = sf::Mouse::getPosition(*window);
	/*std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " "
		<< sf::Mouse::getPosition().y << "\n";*/
		//this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);

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
	this->shape1->setPosition(928 / 2 - 45, 580 / 2 + 580 / 10 - 50 - 20);
	this->shape1->setScale(0.7, 0.7);
	//this->shape1->setSize(sf::Vector2f(150, 150));
	//this->shape1->setFillColor(sf::Color::Red);
	//this->shape1->setOrigin(this->shape1->getSize() / 2.f);

	//load game
	this->texture2->loadFromFile("../Data/btn/ok.png");
	this->shape2->setTexture(*texture2);
	//this->shape2->setSize(sf::Vector2f(100, 100));
	//this->shape2->setOrigin(this->shape2->getSize() / 2.f);
	this->shape2->setScale(0.4, 0.4);
	this->shape2->setPosition(928 / 2 - 928 / 4 - 10, 580 - 580 / 8 - 20);

	//highscore game
	this->texture3->loadFromFile("../Data/btn/prize.png");
	this->shape3->setTexture(*texture3);
	//this->shape3->setSize(sf::Vector2f(100, 100));
	//this->shape3->setOrigin(this->shape3->getSize() / 2.f);
	this->shape3->setScale(0.4, 0.4);
	this->shape3->setPosition(928 / 2 - 928 / 12 - 10, 580 - 580 / 8 - 20);

	//setting game
	this->texture4->loadFromFile("../Data/btn/music.png");
	this->shape4->setTexture(*texture4);
	//this->shape4->setSize(sf::Vector2f(100, 100));
	//this->shape4->setOrigin(this->shape4->getSize() / 2.f);
	this->shape4->setScale(0.4, 0.4);
	this->shape4->setPosition(928 / 2 + 928 / 12 - 10, 580 - 580 / 8 - 20);

	//exit game
	this->texture5->loadFromFile("../Data/btn/close.png");
	this->shape5->setTexture(*texture5);
	//this->shape5->setSize(sf::Vector2f(100, 100));
	//this->shape5->setOrigin(this->shape5->getSize() / 2.f);
	this->shape5->setScale(0.4, 0.4);
	this->shape5->setPosition(928 / 2 + 928 / 4 - 10, 580 - 580 / 8 - 20);


}

void GSMenu::Update()
{
	//std::cout << "1" << "\n";
	if (this->shape1->getGlobalBounds().
		contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		//std::cout << "Hovered over button!" << std::endl;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::cout << "Button pressed" << std::endl; 
			this->currentState = StateTypes::PLAY;
		}
	}

	if (this->shape2->getGlobalBounds().
		contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		//std::cout << "Hovered over button!" << std::endl;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::cout << "Button pressed" << std::endl;
			this->currentState = StateTypes::LOADGAME;
		}
	}
	if (this->shape3->getGlobalBounds().
		contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		//std::cout << "Hovered over button!" << std::endl;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::cout << "Button pressed" << std::endl;
			//this->currentState = StateTypes::HIGHSCORE;
		}
	}
	if (this->shape4->getGlobalBounds().
		contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		//std::cout << "Hovered over button!" << std::endl;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::cout << "Button pressed" << std::endl;
			if (music.getVolume() != 0) music.setVolume(0);
			else music.setVolume(100);
		}
	}
	if (this->shape5->getGlobalBounds().
		contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		//std::cout << "Hovered over button!" << std::endl;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->window->close();
			//std::cout << "Button pressed" << std::endl;
			//this->currentState = StateTypes::END;
		}
	}
}

void GSMenu::Render()
{
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

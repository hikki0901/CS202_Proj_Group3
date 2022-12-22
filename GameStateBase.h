#pragma once
#include "Player.h"
#include <iostream>
#include <fstream>

enum StateTypes
{
	INVALID = 0,
	MENU = 1,
	PLAY = 2,
	LOADGAME,
	HIGHSCORE,
	SETTING,
	END,
	SAVEGAME,
};

class GameStateBase
{
private:
public:
	GameStateBase() {};
	virtual ~GameStateBase() {};

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;


};

#pragma once
#include "Player.h"
#include <iostream>
#include <fstream>

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

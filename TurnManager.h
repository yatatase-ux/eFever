#pragma once
#include "PlayerBase.h"
#include "DPadPlayer.h"
#include "WASDPlayer.h"
#include <memory>

#include "KeyAction.h"

enum class Turn
{
	Dpad,
	WASD
};

class TurnManager
{
private:

	std::unique_ptr<PlayerBase> player;
	Turn nowTurn;

	KeyAction* key;

public:

	TurnManager(KeyAction* arg_key);

	void Input();
	void Update();
	void Draw();

	Int2 GetSelectCell();

	void ChangeTurn();
};


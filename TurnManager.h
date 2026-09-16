#pragma once
#include "PlayerBase.h"
#include "DPadPlayer.h"
#include "WASDPlayer.h"
#include <memory>
#include "KeyAction.h"
#include "Grid.h"
#include "Int2.h"
#include "TurnEnum.h"


class TurnManager
{
private:
	KeyAction* key;

	std::unique_ptr<PlayerBase> player;
	Turn nowTurn;

	Grid grid;

	Int2 selectCell;

public:

	TurnManager(KeyAction* arg_key);

	void Input();
	bool Update();
	void Draw();

	Int2 GetSelectCell();

	void ChangeTurn();
};


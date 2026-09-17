#pragma once
#include <memory>
#include "Int2.h"
#include "KeyAction.h"
#include "TurnEnum.h"
#include "Grid.h"
#include "WinChecker.h"

#include "PlayerBase.h"
#include "DPadPlayer.h"
#include "WASDPlayer.h"


class TurnManager
{
private:
	KeyAction* key;

	std::unique_ptr<PlayerBase> player;
	Int2 selectCell;
	Turn nowTurn;

	Grid grid;

	WinChecker winChecker;

public:

	TurnManager(KeyAction* arg_key);

	void Input();
	bool Update();
	void Draw();

	Int2 GetSelectCell();

	void ChangeTurn();
};


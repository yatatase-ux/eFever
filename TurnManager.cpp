#include "TurnManager.h"

TurnManager::TurnManager(KeyAction* arg_key)
	:key(arg_key),
	winChecker(&grid)
{
	player = std::make_unique<DPadPlayer>(key);

	nowTurn = Turn::Dpad;

	selectCell = { 0, 0 };
}

bool TurnManager::Input()
{
	bool turnChange = player->Input();

	if (turnChange)
	{
		bool placeFailed = grid.SetMark(nowTurn, selectCell);

		if (placeFailed)
		{
			return false;
		}

		Mark winner;
		GameState result = winChecker.CheckFinish(winner);
		if (result != GameState::InProgress)
		{
			return true;
		}

		ChangeTurn();
	}
	return false;
}

bool TurnManager::Update()
{
	player->Update();
	selectCell = player->GetSelectCell();

//	bool finishGame = winChecker.CheckFinish();

	return false;
}

void TurnManager::Draw()
{
	grid.Draw(selectCell);
	player->Draw();
}

Int2 TurnManager::GetSelectCell()
{
	return player->GetSelectCell();
}

void TurnManager::ChangeTurn()
{
	if (nowTurn == Turn::Dpad)
	{
		player = std::make_unique<WASDPlayer>(key);
		nowTurn = Turn::WASD;
	}
	else
	{
		player = std::make_unique<DPadPlayer>(key);
		nowTurn = Turn::Dpad;
	}
}
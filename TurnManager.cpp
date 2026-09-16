#include "TurnManager.h"

TurnManager::TurnManager(KeyAction* arg_key)
	:key(arg_key)
{
	player = std::make_unique<DPadPlayer>(key);

	nowTurn = Turn::Dpad;

	selectCell = { 0, 0 };
}

void TurnManager::Input()
{
	bool turnChange = player->Input();

	if (turnChange)
	{
		ChangeTurn();
	}
}

bool TurnManager::Update()
{
	player->Update();
	selectCell = player->GetSelectCell();

	bool finishGame = grid.Update();

	return finishGame;
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
	bool CheckNoMark = grid.SetMark(nowTurn, selectCell);

	if (CheckNoMark) return;

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
#include "TurnManager.h"

TurnManager::TurnManager(KeyAction* arg_key)
	:key(arg_key)
{
	player = std::make_unique<DPadPlayer>(key);

	nowTurn = Turn::Dpad;
}

void TurnManager::Input()
{
	bool turnChange = player->Input();

	if (turnChange)
	{
		ChangeTurn();
	}
}

void TurnManager::Update()
{
	player->Update();
}

void TurnManager::Draw()
{
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
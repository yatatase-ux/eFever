#pragma once
#include <memory>
#include "Float2.h"
#include "Int2.h"
#include "Cell.h"
#include "WindowSize.h"
#include "KeyAction.h"

#include "PlayerBase.h"
#include "DPadPlayer.h"
#include "WASDPlayer.h"

class Grid
{
private:
	Float2 gridPos;
	Float2 gridSize;

	Cell cells[3][3];

	Int2 selectCell;

	std::unique_ptr<PlayerBase> player;

	KeyAction* key;

public:

	Grid(KeyAction* arg_key);

	void Input();
	void Update();
	void Draw();

};
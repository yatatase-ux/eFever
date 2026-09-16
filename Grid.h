#pragma once
#include <memory>
#include "Float2.h"
#include "Int2.h"
#include "Cell.h"
#include "WindowSize.h"
#include "KeyAction.h"
#include "TurnEnum.h"

class Grid
{
private:
	Float2 gridPos;
	Float2 gridSize;

	Cell cells[3][3];

public:

	Grid();

	void Input();
	bool Update();
	void Draw(Int2 selectCell);

	bool SetMark(Turn now, Int2 selectCell);
};
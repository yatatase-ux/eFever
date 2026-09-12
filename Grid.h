#pragma once
#include "Float2.h"
#include "Cell.h"
#include "WindowSize.h"

class Grid
{
private:
	Float2 gridPos;
	Float2 gridSize;

	Cell cells[3][3];

public:

	Grid();

	void Update();
	void Draw();

};
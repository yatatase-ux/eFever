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
	Float2 pos = {0.0f, 0.0f};

public:

	Grid();

	void Update();
	void Draw();

};
#include "Grid.h"
#include "DxLib.h"
#include "Function.h"

Grid::Grid():
	cells{
	{
	pos,pos,pos
},
	{
		pos, pos, pos
}
}
{
	gridPos = { WINDOW_WF / 2.0f, WINDOW_HF / 2.0f };
	gridSize = { 500.0f, 500.0f };
}

void Grid::Update()
{

}

void Grid::Draw()
{
	// óŒÇÃî’
	DrawCenterBox(gridPos, gridSize, GetColor(0, 128, 0), TRUE);
	// çïÇÃÉâÉCÉì
	Float2 sPos = gridPos - gridSize / 2.0f;
	Float2 ePos = sPos + gridSize;
	float n = gridSize.x / 3.0f;
	for (int i = 0; i < 4; i++)
	{
		DrawLineAA(sPos.x + i * n, sPos.y, sPos.x + i * n, ePos.y, GetColor(0, 0, 0), 5.0f);
		DrawLineAA(sPos.x, sPos.y + i * n, ePos.x, sPos.y + i * n, GetColor(0, 0, 0), 5.0f);
	}

	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			cells[h][w].Draw();
		}
	}
	
}
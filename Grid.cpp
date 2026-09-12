#include "Grid.h"
#include "DxLib.h"
#include "Function.h"

Grid::Grid(KeyAction* arg_key)
	:key(arg_key)
{
	gridPos = { WINDOW_WF / 2.0f, WINDOW_HF / 2.0f };
	gridSize = { 500.0f, 500.0f };

	// 盤の左上座標(基準点)を計算
	Float2 sPos = gridPos - gridSize / 2.0f;
	// 1マスの一辺のサイズ(500 / 3)
	float cellSize = gridSize.x / 3.0f;

	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			// 各マスの中心座標を計算
			// sPos(左上)から、w列目・h行目ぶん右下にずらし、
			// さらにマス半分ぶん(cellSize / 2)足して中心に合わせる
			Float2 cellPos = sPos + Float2(
				cellSize * w + cellSize / 2.0f,
				cellSize * h + cellSize / 2.0f
			);

			// デフォルト構築されたCellに、正しい座標を持つCellを代入し直す
			// (Cell(Float2)コンストラクタが呼ばれ、mark = Mark::Noneもここで設定される)
			cells[h][w] = Cell(cellPos);
		}
	}

	selectCell = { 0, 0 };

	player = std::make_unique<DPadPlayer>(key);
}

void Grid::Input()
{
	player->Input();
}

void Grid::Update()
{
	player->Update();
}

void Grid::Draw()
{
	// 緑の盤
	DrawCenterBox(gridPos, gridSize, GetColor(0, 128, 0), TRUE);
	// 黒のライン
	Float2 sPos = gridPos - gridSize / 2.0f;
	Float2 ePos = sPos + gridSize;
	float n = gridSize.x / 3.0f;
	for (int i = 0; i < 4; i++)
	{
		DrawLineAA(sPos.x + i * n, sPos.y, sPos.x + i * n, ePos.y, GetColor(0, 0, 0), 5.0f);
		DrawLineAA(sPos.x, sPos.y + i * n, ePos.x, sPos.y + i * n, GetColor(0, 0, 0), 5.0f);
	}

	// マルとバツの描画
	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			cells[h][w].Draw();
		}
	}

	Float2 selectPos = cells[selectCell.y][selectCell.x].GetPos();
	DrawCenterBox(selectPos, { gridSize.x / 3.0f, gridSize.y / 3.0f }, GetColor(255, 255, 0), FALSE, 5.0f);
	
}
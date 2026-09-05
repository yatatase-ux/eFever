#include "ScenePlay.h"

sCONSTRUCTOR(ScenePlay)
{
	maru_image = LoadGraph("image/maru.png");
	batu_image = LoadGraph("image/batu.png");
	hanten_image = LoadGraph("image/hanten.png");
	kakutei_image = LoadGraph("image/kakutei.png");
	hantenkakutei_image = LoadGraph("image/hantenkakutei.png");
	puchun_image = LoadGraph("image/puchun.jpg");

	gridPos = { WINDOW_WF / 2.0f, WINDOW_HF / 2.0f };
	gridSize = { 500.0f, 500.0f };
}

sInput(ScenePlay)
{
	if (key->Push(SPACE))
	{
		return SceneState::Result;
	}

	return SceneState::None;
}

sUpdate(ScenePlay)
{

}

sDraw(ScenePlay)
{
	DrawCenterBox(gridPos, gridSize, GetColor(0, 128, 0), TRUE);

	Float2 sPos = gridPos - gridSize / 2.0f;
	Float2 ePos = sPos + gridSize;
	float n = gridSize.x / 3.0f;
	for (int i = 0; i < 4; i++)
	{
		DrawLineAA(sPos.x + i * n, sPos.y, sPos.x + i * n, ePos.y, GetColor(0,0,0), 5.0f);
		DrawLineAA(sPos.x, sPos.y + i * n, ePos.x, sPos.y + i * n, GetColor(0,0,0), 5.0f);
	}
	DrawGraph(558, 440, maru_image, TRUE);
	DrawGraph(558-166, 440, batu_image, TRUE);
}

sSound(ScenePlay)
{

}
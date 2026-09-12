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
	grid.Update();
}

sDraw(ScenePlay)
{

	grid.Draw();

	DrawGraph(558, 440, maru_image, TRUE);
	DrawGraph(558-166, 440, batu_image, TRUE);
}

sSound(ScenePlay)
{

}
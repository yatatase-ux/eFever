#include "ScenePlay.h"

sCONSTRUCTOR(ScenePlay)
{
	Cell::ImageLoad();

	hanten_image = LoadGraph("image/hanten.png");
	kakutei_image = LoadGraph("image/kakutei.png");
	hantenkakutei_image = LoadGraph("image/hantenkakutei.png");
	puchun_image = LoadGraph("image/puchun.jpg");

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
}

sSound(ScenePlay)
{

}
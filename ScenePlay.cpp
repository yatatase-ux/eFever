#include "ScenePlay.h"

sCONSTRUCTOR(ScenePlay)
{
	Cell::ImageLoad();

	sp.Init();

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

	if (key->Push(ONE))
	{
		sp.SetMovieFlag(true);
	}

	return SceneState::None;
}

sUpdate(ScenePlay)
{
	grid.Update();

	sp.Update();
}

sDraw(ScenePlay)
{
	grid.Draw();

	sp.Draw();
}

sSound(ScenePlay)
{

}
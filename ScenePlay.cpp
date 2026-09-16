#include "ScenePlay.h"

sCONSTRUCTOR(ScenePlay),
TM{TurnManager(key)}
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
	if (key->Push(ONE))
	{
		sp.SetMovieFlag(true);
	}

	TM.Input();

	return SceneState::None;
}

sUpdate(ScenePlay)
{
	bool GoNextScene = TM.Update();
	if (GoNextScene)
	{
		return SceneState::Result;
	}

	sp.Update();

	return SceneState::None;
}

sDraw(ScenePlay)
{
	TM.Draw();
	sp.Draw();
}

sSound(ScenePlay)
{

}
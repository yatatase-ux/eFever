#include "ScenePlay.h"

sCONSTRUCTOR(ScenePlay),
TM{TurnManager(key)}
{
	Cell::ImageLoad();

	sp.Init();
	pre.Init();

	hanten_image = LoadGraph("image/hanten.png");
	kakutei_image = LoadGraph("image/kakutei.png");
	hantenkakutei_image = LoadGraph("image/hantenkakutei.png");
	puchun_image = LoadGraph("image/puchun.jpg");

	BG = LoadGraph("image/bg.png");

}

ScenePlay::~ScenePlay()
{
	DeleteGraph(hanten_image);
	DeleteGraph(kakutei_image);
	DeleteGraph(hantenkakutei_image);
	DeleteGraph(puchun_image);
	DeleteGraph(BG);
}

sInput(ScenePlay)
{
	if (key->Push(ONE))
	{
		if (pre.Lottery())
		{
			sp.SetMovieFlag(true);
		}
	}

	bool GoResult = TM.Input();
	if(GoResult)	return SceneState::Result;

	return SceneState::None;
}

sUpdate(ScenePlay)
{
	bool GoNextScene = TM.Update();
	if (GoNextScene)	return SceneState::Result;	

	sp.Update();

	return SceneState::None;
}

sDraw(ScenePlay)
{
	DrawExtendGraph(0, 0, WINDOW_WI, WINDOW_HI, BG, FALSE);
	TM.Draw();
	sp.Draw();
}

sSound(ScenePlay)
{

}
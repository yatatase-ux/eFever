#include "ScenePlay.h"
#include "Function.h"
#include "WindowSize.h"

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

	BG = LoadGraph("image/play_bg.png");

	circleImage = LoadGraph("image/maru.png");
	crossImage = LoadGraph("image/batu.png");

	stage = PlayStage::InGame;

}

ScenePlay::~ScenePlay()
{
	DeleteGraph(hanten_image);
	DeleteGraph(kakutei_image);
	DeleteGraph(hantenkakutei_image);
	DeleteGraph(puchun_image);
	DeleteGraph(BG);
	DeleteGraph(circleImage);
	DeleteGraph(crossImage);
}

sInput(ScenePlay)
{
	switch (stage)
	{
	case PlayStage::InGame:
	{

		if (key->Push(ONE))
		{
			if (pre.Lottery())
			{
				sp.SetMovieFlag(true);
			}
		}

		bool GoResult = TM.Input();
		if (GoResult)	
		{
			stage = PlayStage::Result;
			winner = TM.GetWinner();
		}

		break;
	}
	case PlayStage::Result:
		if (key->Push(ENTER) || key->Push(SPACE))
			return SceneState::End;
		break;
	}

	return SceneState::None;
}

sUpdate(ScenePlay)
{
	bool GoNextScene = TM.Update();
	if (GoNextScene)	return SceneState::End;	

	sp.Update();

	return SceneState::None;
}

sDraw(ScenePlay)
{
	DrawExtendGraph(0, 0, WINDOW_WI, WINDOW_HI, BG, FALSE);
	TM.Draw();
	sp.Draw();

	if (stage == PlayStage::Result)
	{
		// 半透明(0：完全透明　～　255：完全不透明)
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawFillBox(0, 0, WINDOW_WI, WINDOW_HI, GetColor(0, 0, 0));
		// 元に戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		switch (winner)
		{
		case Mark::Circle:
			DrawRotaGraph(WINDOW_WF / 2.0f, WINDOW_HF / 2.0f, 3.0f, 0.0f, circleImage, TRUE);
			DrawCenterText(WINDOW_WF / 2.0f, WINDOW_HF / 2.0f, "十字キープレイヤーの勝利！！",
				GetColor(255, 255, 0), 75.0f);
			break;

		case Mark::Cross:
			DrawRotaGraph(WINDOW_WF / 2.0f, WINDOW_HF / 2.0f, 3.0f, 0.0f, crossImage, TRUE);
			DrawCenterText(WINDOW_WF / 2.0f, WINDOW_HF / 2.0f, "WASDプレイヤーの勝利！！",
				GetColor(255, 255, 0), 75.0f);
			break;
		}
	}
}

sSound(ScenePlay)
{

}
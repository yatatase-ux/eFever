#include "TurnManager.h"
#include "Function.h"

TurnManager::TurnManager(KeyAction* arg_key)
	:key(arg_key),
	winChecker(&grid)
{
	player = std::make_unique<DPadPlayer>(key);

	nowTurn = Turn::Dpad;

	selectCell = { 0, 0 };

	sp.Init();
	pre.Init();

	markImage[0] = LoadGraph("image/maru.png");
	keyImage[0] = LoadGraph("image/Dpad.png");
	decideImage[0] = LoadGraph("image/enter.png");
	UIpos[0].x = 1070.0f;

	markImage[1] = LoadGraph("image/batu.png");
	keyImage[1] = LoadGraph("image/WASD.png");
	decideImage[1] = LoadGraph("image/space.png");

	UIpos[1].x = 210;
	for (int i = 0; i < 2; i++)
	{
		UIpos[i].y = 150.0f;
	}

}

TurnManager::~TurnManager()
{
	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(markImage[i]);
		DeleteGraph(keyImage[i]);
		DeleteGraph(decideImage[i]);
	}
}

bool TurnManager::Input()
{
	bool turnChange = player->Input();

	if (key->Push(ONE))
	{
		pre.Start();
		effectState = EffectState::Falling;  // 落下開始
	}

	if (turnChange)
	{
		// 既に選択したマスに置いてあるなどで、〇×を置けなかった時
		bool placeFailed = grid.SetMark(nowTurn, selectCell);
		if (placeFailed)
		{
			return false;
		}

		// ゲームが終了する時
		GameState result = winChecker.CheckFinish(winner);
		if (result != GameState::InProgress)
		{
			return true;
		}

		int spCount = 0;
		// まだ続いているとき
		for (int h = 0; h < 3; h++)
		{
			for (int w = 0; w < 3; w++)
			{
				// このマスの状態(空/○/×)を取得する
				Mark mark = grid.GetCellMark(h, w);

				// マークが入っていれば(空でなければ)カウントする
				if (mark != Mark::None)
				{
					spCount++;
				}
			}
		}
		// 駒を5つ以上置いてるときに特殊演出の抽選開始
		if(spCount > 4)
		{
			// いったん20％で
			int random = GetRand(100);
			if(random < 20)
			{
				pre.Start();
				effectState = EffectState::Falling;  // 落下開始
			}
		}

		ChangeTurn();	// ターン交代
	}
	return false;
}

bool TurnManager::Update()
{
	switch (effectState)
	{
	case EffectState::Falling:
		// 手が落下中。落ちきったら true が返ってくる
		if (pre.Update())
		{
			effectState = EffectState::Wait;
			delay = 60;     // 60フレーム(約1秒)待つ
		}
		break;

	case EffectState::Wait:
		// 手が落ちきった後のディレイ
		delay--;
		if (delay <= 0)
		{
			// ディレイ終了 → ここで一度だけ抽選する
			if (pre.Lottery())
			{
				// 当選:特殊演出を開始
				sp.SetMovieFlag();
				pre.Reset();            // 手を消す
				grid.SpecialEffect();
				effectState = EffectState::Playing;
				alpha = 255;
			}
			else
			{
				// 外れ:手を消して通常のプレイに戻る
				pre.Reset();
				effectState = EffectState::None;
			}
		}
		break;

	case EffectState::Playing:
		// 演出の再生が終わるのを待つ(下の sp.Update() の後で判定)
		break;

	default:
		break;
	}

	// 演出中以外は、プレイヤーの操作を受け付ける
	if (effectState == EffectState::None || effectState == EffectState::Falling)
	{
		player->Update();
		selectCell = player->GetSelectCell();
		alpha --;
	}

	sp.Update();

	// 演出再生中だけ、終了判定を見る
	if (effectState == EffectState::Playing && sp.IsMovieFinished())
	{
		effectState = EffectState::None;

	}

	if(alpha < 0)
	{
		// 演出で盤面が変わったので、ゲーム終了かどうかを判定する
		GameState result = winChecker.CheckFinish(winner);
		if (result != GameState::InProgress)
		{
			return true;
		}
	}

	return false;
}

void TurnManager::Draw()
{
	grid.Draw(selectCell);
	player->Draw();
	UIDraw();
	// 半透明(0：完全透明　～　255：完全不透明)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawFillBox(0, 0, WINDOW_WI, WINDOW_HF, GetColor(0, 0, 0));
	// 元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	sp.Draw();
	pre.Draw();


//	DrawFormatString(20, 20, GetColor(255, 255, 255), "%d", (int)effectState);
}

Int2 TurnManager::GetSelectCell()
{
	return player->GetSelectCell();
}

void TurnManager::ChangeTurn()
{
	if (nowTurn == Turn::Dpad)
	{
		player = std::make_unique<WASDPlayer>(key);
		nowTurn = Turn::WASD;
	}
	else
	{
		player = std::make_unique<DPadPlayer>(key);
		nowTurn = Turn::Dpad;
	}
}

void TurnManager::UIDraw()
{
	// 〇のプレイヤーUI
	DrawRotaGraph(UIpos[0].x, UIpos[0].y, 1.0, 0.0, markImage[0], TRUE);
	DrawCenterText(UIpos[0].x, UIpos[0].y + 100.0f, "のターン", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos[0].x, UIpos[0].y + 200.0f, 0.7, 0.0, keyImage[0], TRUE);
	DrawCenterText(UIpos[0].x, UIpos[0].y + 300.0f, "で操作", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos[0].x, UIpos[0].y + 380.0f, 0.3, 0.0, decideImage[0], TRUE);
	DrawCenterText(UIpos[0].x, UIpos[0].y + 480.0f, "で決定", GetColor(255, 255, 0), 30);

	// ×のプレイヤーＵＩ
	DrawRotaGraphF(UIpos[1].x, UIpos[1].y, 1.0, 0.0, markImage[1], TRUE);
	DrawCenterText(UIpos[1].x, UIpos[1].y + 100.0f, "のターン", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos[1].x, UIpos[1].y + 200.0f, 0.5, 0.0, keyImage[1], TRUE);
	DrawCenterText(UIpos[1].x, UIpos[1].y + 300.0f, "で操作", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos[1].x, UIpos[1].y + 380.0f, 0.4, 0.0, decideImage[1], TRUE);
	DrawCenterText(UIpos[1].x, UIpos[1].y + 480.0f, "で決定", GetColor(255, 255, 0), 30);

	// 半透明(0：完全透明　～　255：完全不透明)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220);
	switch (nowTurn)
	{
	case Turn::Dpad:
		DrawCenterBox({ UIpos[1].x,  UIpos[1].y + 210.0f }, { 220.0f, 585.0f }, GetColor(0, 0, 0), TRUE);
		break;
	case Turn::WASD:
		DrawCenterBox({ UIpos[0].x,  UIpos[0].y + 210.0f }, { 220.0f, 585.0f }, GetColor(0, 0, 0), TRUE);
		break;
	}
	// 元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
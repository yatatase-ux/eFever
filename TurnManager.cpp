#include "TurnManager.h"

TurnManager::TurnManager(KeyAction* arg_key)
	:key(arg_key),
	winChecker(&grid)
{
	player = std::make_unique<DPadPlayer>(key);

	nowTurn = Turn::Dpad;

	selectCell = { 0, 0 };

	sp.Init();
	pre.Init();
}

bool TurnManager::Input()
{
	bool turnChange = player->Input();

	if (key->Push(ONE))
	{
		
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
				pre.Start();	// 特殊演出処理
			}
		}

		ChangeTurn();	// ターン交代
	}
	return false;
}

bool TurnManager::Update()
{
	player->Update();
	selectCell = player->GetSelectCell();

//	bool finishGame = winChecker.CheckFinish();

	sp.Update();

	pre.Update();

	if (pre.End())
	{
		if (pre.Lottery())
		{
			sp.SetMovieFlag(true);
			pre.Reset();
		}

	}

	return false;
}

void TurnManager::Draw()
{
	grid.Draw(selectCell);
	player->Draw();
	sp.Draw();
	pre.Draw();
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
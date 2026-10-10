#pragma once
#include <memory>
#include "Int2.h"
#include "KeyAction.h"
#include "TurnEnum.h"
#include "Grid.h"
#include "WinChecker.h"

#include "PlayerBase.h"
#include "DPadPlayer.h"
#include "WASDPlayer.h"
#include "SP.h"
#include "PreAlert.h"

// 特殊演出の進行状態
enum class EffectState
{
	None,       // 演出なし(通常のプレイ中)
	Falling,    // 手が落下中
	Wait,       // 手が落ちきった後のディレイ中
	Playing,    // 特殊演出を再生中
};

class TurnManager
{
private:
	KeyAction* key;

	std::unique_ptr<PlayerBase> player;
	Int2 selectCell;
	Turn nowTurn;

	Grid grid;

	WinChecker winChecker;

	Mark winner;

	SP sp;

	PreAlert pre;

	int markImage[2];
	int keyImage[2];
	int decideImage[2];
	Float2 UIpos[2];

	EffectState effectState = EffectState::None;
	int delay = 0;
	float alpha = 0;

public:

	TurnManager(KeyAction* arg_key);
	~TurnManager();


	bool Input();
	bool Update();
	void Draw();

	Int2 GetSelectCell();

	void ChangeTurn();

	Mark GetWinner() { return winner; };

	void UIDraw();
};


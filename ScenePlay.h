#pragma once
#include "SceneBase.h"
#include "Float2.h"
#include "Function.h"
#include "WindowSize.h"

#include "Cell.h"
#include "TurnManager.h"


enum class PlayStage
{
	InGame,
	Result
};

class ScenePlay : public SceneBase
{
private:
	int hanten_image;
	int kakutei_image;
	int hantenkakutei_image;
	int puchun_image;

	int circleImage;
	int crossImage;

	int BG;

	TurnManager TM;

	PlayStage stage;

	Mark winner;

public:

	SCENECLASS(ScenePlay);
	~ScenePlay();
};


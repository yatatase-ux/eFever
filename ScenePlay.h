#pragma once
#include "SceneBase.h"
#include "Float2.h"
#include "Function.h"
#include "WindowSize.h"
#include "SP.h"
#include "Cell.h"
#include "TurnManager.h"
#include "PreAlert.h"
class ScenePlay : public SceneBase
{
private:
	SP sp;
	PreAlert pre;
	int hanten_image;
	int kakutei_image;
	int hantenkakutei_image;
	int puchun_image;

	int BG;

	TurnManager TM;

public:

	SCENECLASS(ScenePlay);
	~ScenePlay();
};


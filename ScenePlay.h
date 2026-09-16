#pragma once
#include "SceneBase.h"
#include "Float2.h"
#include "Function.h"
#include "WindowSize.h"
#include "SP.h"
#include "Cell.h"
#include "TurnManager.h"

class ScenePlay : public SceneBase
{
private:
	SP sp;
	int hanten_image;
	int kakutei_image;
	int hantenkakutei_image;
	int puchun_image;

	TurnManager TM;

public:

	SCENECLASS(ScenePlay);

};


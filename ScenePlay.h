#pragma once
#include "SceneBase.h"
#include "Float2.h"
#include "Function.h"
#include "WindowSize.h"
#include "SP.h"
#include "Grid.h"

class ScenePlay : public SceneBase
{
private:
	Grid grid;
	SP sp;
	int hanten_image;
	int kakutei_image;
	int hantenkakutei_image;
	int puchun_image;

public:

	SCENECLASS(ScenePlay);

};


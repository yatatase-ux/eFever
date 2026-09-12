#pragma once
#include "SceneBase.h"
#include "Float2.h"
#include "Function.h"
#include "WindowSize.h"

#include "Grid.h"

class ScenePlay : public SceneBase
{
private:
	Grid grid;

	int hanten_image;
	int kakutei_image;
	int hantenkakutei_image;
	int puchun_image;

public:

	SCENECLASS(ScenePlay);

};


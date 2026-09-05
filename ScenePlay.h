#pragma once
#include "SceneBase.h"
#include "Float2.h"
#include "Function.h"
#include "WindowSize.h"

class ScenePlay : public SceneBase
{
private:

	Float2 gridPos;
	Float2 gridSize;

	int maru_image;
	int batu_image;
	int hanten_image;
	int kakutei_image;
	int hantenkakutei_image;
	int puchun_image;

public:

	SCENECLASS(ScenePlay);

};


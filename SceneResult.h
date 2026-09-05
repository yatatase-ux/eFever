#pragma once
#include "SceneBase.h"

class SceneResult : public SceneBase
{
	int win_image;
	int lose_image;
	int arrow;
	int end_image;
	int continue_image;

public:
	SCENECLASS(SceneResult);
};
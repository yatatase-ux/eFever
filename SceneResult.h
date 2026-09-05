#pragma once
#include "SceneBase.h"
#include "Float2.h"

class SceneResult : public SceneBase
{
	int win_image;
	int lose_image;
	int arrow;
	int end_image;
	int continue_image;

	Float2 arrow_pos;

	bool end_mode;

public:
	SCENECLASS(SceneResult);
};
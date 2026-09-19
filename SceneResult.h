#pragma once
#include "SceneBase.h"
#include "Float2.h"

class SceneResult : public SceneBase
{
	int win_image;
	int lose_image;

public:
	SCENECLASS(SceneResult);
	~SceneResult();
};
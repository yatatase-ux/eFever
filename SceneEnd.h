#pragma once
#include "SceneBase.h"
#include "Float2.h"

class SceneEnd : public SceneBase
{
private:

	int arrow;
	Float2 arrow_pos;

	int end_image;
	int continue_image;

	bool end_mode;

	int highBG;
	int lowBG;

public:

	SCENECLASS(SceneEnd);

	~SceneEnd();

};


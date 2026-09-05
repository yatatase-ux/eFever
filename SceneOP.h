#pragma once
#include "SceneBase.h"
#include "Float2.h"

class SceneOP : public SceneBase
{
private:
	int BG_Image;

	int arrow;
	Float2 arrow_pos;

	bool npc_mode;
public:

	SCENECLASS(SceneOP);

};

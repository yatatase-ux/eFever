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

public:

	SCENECLASS(ScenePlay);

};


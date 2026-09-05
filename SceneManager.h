#pragma once
#include <memory>

#include "SceneBase.h"
#include "SceneOP.h"
#include "ScenePlay.h"
#include "SceneResult.h"

class SceneManager
{
private:

	std::unique_ptr<SceneBase> scene;

public:

	SceneManager();

	void Input();
	void Update();
	void Draw();
	void Sound();

	void SceneChange(SceneState nextScene);
};
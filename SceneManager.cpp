#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = std::make_unique<SceneOP>(&key);
}

void SceneManager::Input()
{
	SceneState next = scene->Input();
	SceneChange(next);
}

void SceneManager::Update()
{
	 scene->Update();
}

void SceneManager::Draw()
{
	scene->Draw();
}

void SceneManager::Sound()
{
	scene->Sound();
}

void SceneManager::SceneChange(SceneState nextScene)
{
	switch (nextScene)
	{
	case SceneState::None:
		break;

	case SceneState::OP:
		scene = std::make_unique<SceneOP>(&key);
		break;

	case SceneState::Play:
		scene = std::make_unique<ScenePlay>(&key);
		break;

	case SceneState::Result:
		scene = std::make_unique<SceneResult>(&key);
		break;
	}
}
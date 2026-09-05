#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = std::make_unique<SceneOP>();
}

void SceneManager::Input()
{
	scene->Input();
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

void SceneManager::SceneChange(int nextScene)
{
	switch (nextScene)
	{
		
	}
}
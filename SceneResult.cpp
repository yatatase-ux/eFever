#include "SceneResult.h"
#include "Function.h"
#include "WindowSize.h"

sCONSTRUCTOR(SceneResult)
{
	win_image = LoadGraph("image/win.png");
	lose_image = LoadGraph("image/lose.png");
}

SceneResult::~SceneResult()
{
	DeleteGraph(win_image);
	DeleteGraph(lose_image);
}

sInput(SceneResult)
{
	if (key->Push(SPACE))
	{
		return SceneState::End;
	}

	return SceneState::None;
}

sUpdate(SceneResult)
{
	return SceneState::None;
}

sDraw(SceneResult)
{
	DrawCenterText(WINDOW_WF / 2.0f, WINDOW_HF / 2.0f, "Reault", GetColor(255, 255, 0), 50);
}

sSound(SceneResult)
{

}
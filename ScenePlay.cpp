#include "ScenePlay.h"

sCONSTRUCTOR(ScenePlay)
{
	gridPos = { WINDOW_WF / 2.0f, WINDOW_HF / 2.0f };
	gridSize = { 500.0f, 500.0f };
}

sInput(ScenePlay)
{
	if (key->Push(SPACE))
	{
		return SceneState::Result;
	}

	return SceneState::None;
}

sUpdate(ScenePlay)
{

}

sDraw(ScenePlay)
{
	DrawCenterBox(gridPos, gridSize, GetColor(0, 128, 0), TRUE);

}

sSound(ScenePlay)
{

}
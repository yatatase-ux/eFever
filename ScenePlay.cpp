#include "ScenePlay.h"

sCONSTRUCTOR(ScenePlay)
{

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
	DrawString(200, 200, "Play", GetColor(255, 255, 255));
}

sSound(ScenePlay)
{

}
#include "SceneResult.h"

sCONSTRUCTOR(SceneResult)
{

}

sInput(SceneResult)
{
	if (key->Push(SPACE))
	{
		return SceneState::OP;
	}

	return SceneState::None;
}

sUpdate(SceneResult)
{

}

sDraw(SceneResult)
{
	DrawString(200, 200, "Result", GetColor(255, 255, 255));
}

sSound(SceneResult)
{

}
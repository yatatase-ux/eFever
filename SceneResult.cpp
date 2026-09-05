#include "SceneResult.h"

sCONSTRUCTOR(SceneResult)
{
	win_image = LoadGraph("image/win.png");
	lose_image = LoadGraph("image/lose.png");
	arrow = LoadGraph("image/yajirusi.png");
	end_image = LoadGraph("image/end.png");
	continue_image = LoadGraph("image/keizoku.png");
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
	DrawGraph(650, 0, continue_image, TRUE);
}

sSound(SceneResult)
{

}
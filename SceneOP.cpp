#include "SceneOP.h"
#include "DxLib.h"

sCONSTRUCTOR(SceneOP)
{
	op_image = LoadGraph("image/OP.png");
}

sInput(SceneOP)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return SceneState::Play;
	}

	return SceneState::None;
}

sUpdate(SceneOP)
{

}

sDraw(SceneOP)
{
	DrawBox(0,0,1280,720,GetColor(255,255,255),TRUE);
	DrawGraph(0, 0, op_image, TRUE);

	SetFontSize(50);
	DrawString(850,500,"NPCêÌ",GetColor(0,0,0));
	DrawString(850,600, "ÉIÉtÉâÉCÉìêÌ", GetColor(0, 0, 0));
}

sSound(SceneOP)
{

}
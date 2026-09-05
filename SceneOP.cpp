#include "SceneOP.h"
#include "DxLib.h"

sCONSTRUCTOR(SceneOP)
{
	op_image = LoadGraph("image/OP.png");
}

sInput(SceneOP)
{

}

sUpdate(SceneOP)
{

}

sDraw(SceneOP)
{
	DrawBox(0,0,1280,720,GetColor(255,255,255),TRUE);
	DrawGraph(0, 0, op_image, TRUE);

}

sSound(SceneOP)
{

}
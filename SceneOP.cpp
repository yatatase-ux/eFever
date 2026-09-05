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
	DrawGraph(0, 0, op_image, TRUE);
}

sSound(SceneOP)
{

}
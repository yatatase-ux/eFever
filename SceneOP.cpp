#include "SceneOP.h"
#include "DxLib.h"
#include "Function.h"
#include "WindowSize.h"

sCONSTRUCTOR(SceneOP)
{
	BG_Image = LoadGraph("image/OP.png");
	count = 50;
}

SceneOP::~SceneOP()
{
	DeleteGraph(BG_Image);
}

sInput(SceneOP)
{
	if (key->Push(ENTER) || key->Push(SPACE))
	{
		return SceneState::Play;
	}

	count--;
	if (count < 0) count = 50;

	return SceneState::None;
}

sUpdate(SceneOP)
{
	return SceneState::None;
}

sDraw(SceneOP)
{
	DrawBox(0,0,1280,720,GetColor(255,255,255),TRUE);
	DrawGraph(0, 0, BG_Image, TRUE);

	if(count > 10)
	{
		DrawCenterText(WINDOW_WF / 2.0f, 600.0f, "SPACE Ç‹ÇΩÇÕ ENTER Ç≈ÉQÅ[ÉÄÇ÷", GetColor(0, 0, 0), 50);
	}
	
}

sSound(SceneOP)
{

}
#include "SceneOP.h"
#include "DxLib.h"

sCONSTRUCTOR(SceneOP)
{
	BG_Image = LoadGraph("image/OP.png");

	arrow = LoadGraph("image/yajirusi.png");
	arrow_pos = { 750.0f, 470.0f };

	npc_mode = true;

}

sInput(SceneOP)
{
	if (key->Push(SPACE))
	{
		return SceneState::Play;
	}

	if (key->Push(UP) || key->Push(DOWN)) npc_mode = (npc_mode) ? false : true;

	if(npc_mode) arrow_pos = { 750.0f, 470.0f };
	else		 arrow_pos = { 750.0f, 570.0f };

	return SceneState::None;
}

sUpdate(SceneOP)
{

}

sDraw(SceneOP)
{
	DrawBox(0,0,1280,720,GetColor(255,255,255),TRUE);
	DrawGraph(0, 0, BG_Image, TRUE);

	DrawGraphF(arrow_pos.x, arrow_pos.y, arrow, TRUE);

	SetFontSize(50);
	DrawString(850,500,"NPCêÌ",GetColor(0,0,0));
	DrawString(850,600, "ÉtÉåÉìÉhêÌ", GetColor(0, 0, 0));
	
}

sSound(SceneOP)
{

}
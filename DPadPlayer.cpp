#include "DPadPlayer.h"
#include "Function.h"

PlayerConstructor(DPadPlayer)
{
	selectCell = { 0, 0 };
	markImage = LoadGraph("image/maru.png");

	keyImage = LoadGraph("image/Dpad.png");
	decideImage = LoadGraph("image/enter.png");

	UIpos_x = 1100.0f;
}

DPadPlayer::~DPadPlayer()
{
	DeleteGraph(markImage);
	DeleteGraph(keyImage);
	DeleteGraph(decideImage);
}

PlayerInput(DPadPlayer)
{
	if (key->Push(UP))
	{
		selectCell.y--;
		if (selectCell.y < 0) selectCell.y = 0;
	}
	else if (key->Push(DOWN))
	{
		selectCell.y++;
		if (selectCell.y > 2) selectCell.y = 2;
	}
	else if (key->Push(RIGHT))
	{
		selectCell.x++;
		if (selectCell.x > 2) selectCell.x = 2;
	}
	else if (key->Push(LEFT))
	{
		selectCell.x--;
		if (selectCell.x < 0) selectCell.x = 0;
	}

	if (key->Push(ENTER))
	{
		return true;
	}

	return false;
}

PlayerUpdate(DPadPlayer)
{

}

void DPadPlayer::Draw()
{
	DrawRotaGraph(UIpos_x, 200.0f, 1.0, 0.0, markImage, TRUE);
	DrawCenterText(UIpos_x, 300.0f, "ÇÃÉ^Å[Éì", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos_x, 400.0f, 0.7, 0.0, keyImage, TRUE);
	DrawCenterText(UIpos_x, 500.0f, "Ç≈ëÄçÏ", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos_x, 580.0f, 0.3, 0.0, decideImage, TRUE);
	DrawCenterText(UIpos_x, 680.0f, "Ç≈åàíË", GetColor(255, 255, 0), 30);
}

void DPadPlayer::Sound()
{

}

Int2 DPadPlayer::GetSelectCell()
{
	return selectCell;
}
#include "DPadPlayer.h"
#include "Function.h"

PlayerConstructor(DPadPlayer)
{
	selectCell = { 0, 0 };
	image = LoadGraph("image/maru.png");
}

DPadPlayer::~DPadPlayer()
{
	DeleteGraph(image);
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
	DrawRotaGraph(1100, 200, 1.0, 0.0, image, TRUE);
	DrawCenterText(1100.0f, 300.0f, "ÇÃÉ^Å[Éì", GetColor(255, 255, 0), 30);
}

void DPadPlayer::Sound()
{

}

Int2 DPadPlayer::GetSelectCell()
{
	return selectCell;
}
#include "DPadPlayer.h"

PlayerConstructor(DPadPlayer)
{
	selectCell = { 0, 0 };
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
}

PlayerUpdate(DPadPlayer)
{

}

void DPadPlayer::Draw()
{

}

void DPadPlayer::Sound()
{

}

Int2 DPadPlayer::GetSelectCell()
{
	return selectCell;
}
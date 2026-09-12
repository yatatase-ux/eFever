#include "DPadPlayer.h"

PlayerConstructor(DPadPlayer)
{
	selectCell = { 0, 0 };
}

PlayerInput(DPadPlayer)
{
	if (key->Push(UP))
	{
		selectCell.x--;
	}
	else if (key->Push(DOWN))
	{
		selectCell.y++;
	}
	else if (key->Push(RIGHT))
	{
		selectCell.x++;
	}
	else if (key->Push(LEFT))
	{
		selectCell.x--;
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
#include "WASDPlayer.h"

PlayerConstructor(WASDPlayer)
{
	selectCell = { 0, 0 };
}

PlayerInput(WASDPlayer)
{
	if (key->Push(W))
	{
		selectCell.y--;
		if (selectCell.y < 0) selectCell.y = 0;
	}
	else if (key->Push(S))
	{
		selectCell.y++;
		if (selectCell.y > 2) selectCell.y = 2;
	}
	else if (key->Push(D))
	{
		selectCell.x++;
		if (selectCell.x > 2) selectCell.x = 2;
	}
	else if (key->Push(A))
	{
		selectCell.x--;
		if (selectCell.x < 0) selectCell.x = 0;
	}
}

PlayerUpdate(WASDPlayer)
{

}

void WASDPlayer::Draw()
{

}

void WASDPlayer::Sound()
{

}

Int2 WASDPlayer::GetSelectCell()
{
	return selectCell;
}
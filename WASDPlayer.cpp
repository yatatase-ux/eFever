#include "WASDPlayer.h"
#include "Function.h"

PlayerConstructor(WASDPlayer)
{
	selectCell = { 0, 0 };
	image = LoadGraph("image/batu.png");
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

	if (key->Push(SPACE))
	{
		return true;
	}

	return false;
}

PlayerUpdate(WASDPlayer)
{

}

void WASDPlayer::Draw()
{
	DrawRotaGraph(180, 200, 1.0, 0.0, image, TRUE);
	DrawCenterText(180.0f, 300.0f, "ÇÃÉ^Å[Éì", GetColor(255, 255, 0), 30);
}

void WASDPlayer::Sound()
{

}

Int2 WASDPlayer::GetSelectCell()
{
	return selectCell;
}
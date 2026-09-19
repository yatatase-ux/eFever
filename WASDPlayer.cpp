#include "WASDPlayer.h"
#include "Function.h"

PlayerConstructor(WASDPlayer)
{
	selectCell = { 0, 0 };
	markImage = LoadGraph("image/batu.png");

	keyImage = LoadGraph("image/WASD.png");
	decideImage = LoadGraph("image/space.png");

	UIpos_x = 180;
}

WASDPlayer::~WASDPlayer()
{
	DeleteGraph(markImage);
	DeleteGraph(keyImage);
	DeleteGraph(decideImage);
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
	DrawRotaGraphF(UIpos_x, 200.0f, 1.0, 0.0, markImage, TRUE);
	DrawCenterText(UIpos_x, 300.0f, "ÇÃÉ^Å[Éì", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos_x, 400.0f, 0.5, 0.0, keyImage, TRUE);
	DrawCenterText(UIpos_x, 500.0f, "Ç≈ëÄçÏ", GetColor(255, 255, 0), 30);

	DrawRotaGraph(UIpos_x, 580.0f, 0.4, 0.0, decideImage, TRUE);
	DrawCenterText(UIpos_x, 680.0f, "Ç≈åàíË", GetColor(255, 255, 0), 30);
}

void WASDPlayer::Sound()
{

}

Int2 WASDPlayer::GetSelectCell()
{
	return selectCell;
}
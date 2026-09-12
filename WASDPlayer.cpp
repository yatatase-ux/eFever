#include "WASDPlayer.h"

PlayerConstructor(WASDPlayer)
{
	selectCell = { 0, 0 };
}

PlayerInput(WASDPlayer)
{
	if (key->Push(W))
	{

	}
	else if (key->Push(S))
	{

	}
	else if (key->Push(D))
	{

	}
	else if (key->Push(A))
	{

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
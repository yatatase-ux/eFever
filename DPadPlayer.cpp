#include "DPadPlayer.h"

DPadPlayer::DPadPlayer(KeyAction* arg_key)
	: key(arg_key)
{

}

void DPadPlayer::Input()
{
	if (key->Push(UP))
	{

	}
	else if (key->Push(DOWN))
	{

	}
	else if (key->Push(RIGHT))
	{

	}
	else if (key->Push(LEFT))
	{

	}
}

void DPadPlayer::Update()
{

}

void DPadPlayer::Draw()
{

}

void DPadPlayer::Sound()
{

}
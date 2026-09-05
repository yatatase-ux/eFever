#pragma once
#include "KeyAction.h"

class DPadPlayer
{
private:

	KeyAction* key;

public:

	DPadPlayer(KeyAction* arg_key);

	void Input();
	void Update();
	void Draw();
	void Sound();

};


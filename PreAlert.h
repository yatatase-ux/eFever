#pragma once

class PreAlert
{
	int pre;
	int pre_img;
	int pre_posy;
public:
	void Init();

	bool Lottery();
	void Update();
	void Draw();
};
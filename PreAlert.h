#pragma once

class PreAlert
{
	int pre;
	int pre_img;
	int pre_posy;
	bool active;
	bool end;

	int count;
public:
	void Init();

	bool Lottery();
	bool Update();
	void Draw();

	void Start();
	bool End();
	void Reset();
};
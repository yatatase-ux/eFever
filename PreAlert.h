#pragma once

class PreAlert
{
	int pre;
	int pre_img;
	int pre_posy;
	bool active;
	bool end;
public:
	void Init();

	bool Lottery();
	void Update();
	void Draw();

	void Start();
	bool End();
	void Reset();
};
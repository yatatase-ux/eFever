#pragma once
#include <iostream>


class SP
{
private:
	//  “®‰æ•Ï”
	int puchun;
	//  Ä¶ŠÔ
	int movie_timer;
	
	bool movie_flag;

public:

	void Init();
	void Update();
	void SetMovieFlag(bool flag);
	void Draw();
	void end();
};
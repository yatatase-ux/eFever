#include "SP.h"
#include "DxLib.h"


void SP::Init()
{
	puchun = LoadGraph("image/puchun.mp4");
	movie_flag = false;
}

void SP::Update()
{
	if (movie_flag)
	{
		PlayMovieToGraph(puchun);
	}
}


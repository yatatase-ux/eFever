#include "SP.h"
#include "DxLib.h"


void SP::Init()
{
	puchun = LoadGraph("image/puchun.mp4");
	movie_flag = false;
}

void SP::SetMovieFlag(bool flag)
{
	movie_flag = flag;

	if (movie_flag)
	{
		// “®‰æ‚ğÅ‰‚É–ß‚·
		SeekMovieToGraph(puchun, 0);

		PlayMovieToGraph(puchun);
	}
}

void SP::Update()
{
	if (movie_flag)
	{
		int state = GetMovieStateToGraph(puchun);

		if (state <= 0)
		{
			movie_flag = false;
		}
	}
}

void SP::Draw()
{
	if (movie_flag)
	{
		DrawExtendGraph(0, 0, 1280, 720, puchun, TRUE);
	}
}

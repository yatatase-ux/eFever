#include "SP.h"
#include "DxLib.h"

SP::~SP()
{
	DeleteGraph(puchun);
}

void SP::Init()
{
	puchun = LoadGraph("image/puchun.mp4");
	movie_flag = false;
}
//  プチュンながれるフラグ
void SP::SetMovieFlag(bool flag)
{
	movie_flag = flag;

	if (movie_flag)
	{
		// 動画を最初に戻す
		SeekMovieToGraph(puchun, 0);

		PlayMovieToGraph(puchun);
	}
}

//  プチュン
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

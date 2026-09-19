#include "SceneEnd.h"
#include "WindowSize.h"

sCONSTRUCTOR(SceneEnd)
{
	arrow = LoadGraph("image/yajirusi.png");
	end_image = LoadGraph("image/end.png");
	continue_image = LoadGraph("image/keizoku.png");
	arrow = LoadGraph("image/yajirusi.png");

	end_mode = true;
	arrow_pos = { 750.0f, 570.0f };

	highBG = LoadGraph("image/endHighBG.jpg");
	lowBG = LoadGraph("image/endLowBG.jpg");
}

SceneEnd::~SceneEnd()
{
	DeleteGraph(arrow);
	DeleteGraph(end_image);
	DeleteGraph(continue_image);
	DeleteGraph(highBG);
	DeleteGraph(lowBG);
}

sInput(SceneEnd)
{
	if (key->Push(UP) || key->Push(DOWN)) end_mode = (end_mode) ? false : true;

	if (end_mode)
	{
		arrow_pos = { 500.0f, 190.0f };
		if (key->Push(ENTER) || key->Push(SPACE))
		{
			return SceneState::Play;
		}
	}
	else
	{
		arrow_pos = { 750.0f, 520.0f };
		if (key->Push(ENTER) || key->Push(SPACE))
		{
			return SceneState::OP;
		}
	}

	return SceneState::None;
}

sUpdate(SceneEnd)
{
	return SceneState::None;
}

sDraw(SceneEnd)
{
	if (end_mode)
	{
		DrawExtendGraph(0, 0, WINDOW_WI, WINDOW_HI, highBG, TRUE);
	}
	else
	{
		DrawExtendGraph(0, 0, WINDOW_WI, WINDOW_HI, lowBG, FALSE);
	}

	DrawGraph(500, 0, continue_image, TRUE);
	DrawGraph(900, 500, end_image, TRUE);
	DrawGraph(arrow_pos.x, arrow_pos.y, arrow, TRUE);
}

sSound(SceneEnd)
{

}
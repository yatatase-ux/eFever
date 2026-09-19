#include "SceneEnd.h"

sCONSTRUCTOR(SceneEnd)
{
	arrow = LoadGraph("image/yajirusi.png");
	end_image = LoadGraph("image/end.png");
	continue_image = LoadGraph("image/keizoku.png");
	arrow = LoadGraph("image/yajirusi.png");

	end_mode = false;
	arrow_pos = { 750.0f, 570.0f };
}

SceneEnd::~SceneEnd()
{
	DeleteGraph(arrow);
	DeleteGraph(end_image);
	DeleteGraph(continue_image);
}

sInput(SceneEnd)
{
	if (key->Push(ENTER) || key->Push(SPACE))
	{
		return SceneState::OP;
	}

	if (key->Push(UP) || key->Push(DOWN)) end_mode = (end_mode) ? false : true;

	if (end_mode) arrow_pos = { 500.0f, 190.0f };
	else		 arrow_pos = { 750.0f, 520.0f };

	return SceneState::None;
}

sUpdate(SceneEnd)
{
	return SceneState::None;
}

sDraw(SceneEnd)
{
	DrawGraph(500, 0, continue_image, TRUE);
	DrawGraph(900, 500, end_image, TRUE);
	DrawGraph(arrow_pos.x, arrow_pos.y, arrow, TRUE);
}

sSound(SceneEnd)
{

}
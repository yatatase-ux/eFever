#include "Cell.h"
#include "DxLib.h"
 
int Cell::markImage[MarkMax] = {-1, -1, -1};

Cell::Cell(Float2 arg_pos)
	:pos(arg_pos)
{
	mark = Mark::None;
}

Cell::~Cell()
{
	DeleteGraph(markImage[0]);
	DeleteGraph(markImage[1]);
	DeleteGraph(markImage[2]);
}

void Cell::ImageLoad()
{
	markImage[0] = -1;
	markImage[1] = LoadGraph("image/maru.png");
	markImage[2] = LoadGraph("image/batu.png");
}

void Cell::Draw()
{
	DrawRotaGraphF(pos.x, pos.y, 1.0f, 0.0f, markImage[static_cast<int>(mark)], TRUE);
}

void Cell::SetMark(Mark set)
{
	mark = set;
}
bool Cell::CheckHasMark()
{
	return (mark != Mark::None);
}
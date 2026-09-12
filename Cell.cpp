#include "Cell.h"
#include "DxLib.h"
 
Cell::Cell(Float2 arg_pos)
	:pos(arg_pos)
{
	mark = Mark::None;
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
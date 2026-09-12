#include "Cell.h"
#include "DxLib.h"
 
Cell::Cell(Float2 arg_pos)
	:pos(arg_pos)
{
	mark = Mark::None;
}

void Cell::Draw()
{
	DrawRotaGraphF(pos.x, pos.y, 1.0f, 0.0f, -1, TRUE);
}
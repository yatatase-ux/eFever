#include "Function.h"
void DrawCenterBox(Float2 pos, Float2 size, unsigned int color, bool flag)
{
	Float2 sPos = pos - size / 2.0f;
	Float2 ePos = sPos + size;

	DrawBox(sPos.x, sPos.y, ePos.x, ePos.y, color, flag);
}
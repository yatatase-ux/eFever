#include "Function.h"
void DrawCenterBox(Float2 pos, Float2 size, unsigned int color, bool flag, float LineSize)
{
	Float2 sPos = pos - size / 2.0f;
	Float2 ePos = sPos + size;

	DrawBox(sPos.x, sPos.y, ePos.x, ePos.y, color, flag, LineSize);
}

/// <summary>
/// 中央揃えで文字列を描画する関数
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
/// <param name="text">描画する文字列</param>
/// <param name="color">文字色</param>
/// <param name="size">文字サイズ</param>
void DrawCenterText(float x, float y, const char* text, unsigned int color, float size)
{
	SetFontSize(size);

	int GT_s = strlen(text);

	int GT_w = GetDrawStringWidth(text, GT_s);

	float draw_x = x - (float)GT_w / 2.0f;
	float draw_y = y - (float)size / 2.0f;

	DrawStringF(draw_x, draw_y, text, color);
}
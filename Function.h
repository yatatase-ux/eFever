#pragma once
#include "Float2.h"
#include "DxLib.h"

void DrawCenterBox(Float2 pos, Float2 size, unsigned int color, bool flag, float LineSize = 1.0f);

void DrawCenterText(float x, float y, const char* text, unsigned int color, float size);
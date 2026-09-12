#pragma once
#include "Float2.h"

enum class Mark
{
	None,
	Circle,
	Cross
};

const int MarkMax = 3;

class Cell
{
private:

	Float2 pos;
	Mark mark;
	int markImage[MarkMax];

public:
	Cell() = default;
	Cell(Float2 arg_pos);
	void ImageLoad();

	void Draw();
};


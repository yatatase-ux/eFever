#pragma once
#include "Float2.h"

enum class  Mark
{
	None,
	Circle,
	Cross
};

class Cell
{
private:

	Float2 pos;

	Mark mark;

public:
	Cell() = default;
	Cell(Float2 arg_pos);

	void Draw();
};


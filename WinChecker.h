#pragma once
#include "Cell.h"
#include "Grid.h"

class WinChecker
{
private:

	Grid& grid;

public:

	WinChecker(Grid& arg_grid);

	bool CheckFinish();

};
#pragma once
#include "Cell.h"
#include "Grid.h"

enum class GameState
{
	InProgress, // ‚Ü‚¾Ÿ”s‚ª‚Â‚¢‚Ä‚¢‚È‚¢
	Win,        // ŸÒ‚ªŒˆ‚Ü‚Á‚½
	Draw,       // ˆø‚«•ª‚¯
};

class WinChecker
{
private:

	Grid* grid;

public:

	WinChecker(Grid* arg_grid);

	bool CheckFinish();

};
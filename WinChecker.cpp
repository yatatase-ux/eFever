#include "WinChecker.h"

WinChecker::WinChecker(Grid& arg_grid)
	:grid(arg_grid)
{

}

bool WinChecker::CheckFinish()
{
	// ˆø‚«•ª‚¯‚Ìˆ—------------------------------------
	int CheckFill = 0;
	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			if (grid.CheckCellMark(h, w))
			{
				CheckFill++;
			}
		}
	}
	if (CheckFill >= 9)	return true;
	// --------------------------------------------------



	// ‚Ç‚¿‚ç‚©‚ªŸ‚¿‚Ìˆ—------------------------------

	// --------------------------------------------------


	return false;
}
#include "WinChecker.h"

WinChecker::WinChecker(Grid* arg_grid)
	:grid(arg_grid)
{

}

bool WinChecker::CheckFinish()
{
	int CheckFill = 0;		// マスがフルかどうかのチェックする変数

	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			Mark mark = grid->GetCellMark(h, w);

			// マスが埋まっていれば
			if (mark != Mark::None)
			{
				CheckFill++;	// マスがフルかどうかのチェック変数に１プラスする
			}
		}
	}

	// マスがフルかどうかのチェック変数が９（3*3の全マス）に達したら
	if (CheckFill >= 9)	return true;			// 今は一旦TRUEを返して終了(引き分け)判定


	return false;
}
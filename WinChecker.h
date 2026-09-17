#pragma once
#include "Cell.h"
#include "Grid.h"
#include "TurnEnum.h"

enum class GameState
{
	InProgress, // まだ勝敗がついていない
	Win,        // 勝者が決まった
	Draw,       // 引き分け
};

class WinChecker
{
private:

	Grid* grid;
	
	/// <summary>
	/// 勝者がいるかどうかを判定し、勝者が見つかった場合は out_winner にそのマークを設定する const
	/// </summary>
	/// <param name="out_winner">勝者のマークを格納する出力パラメータ。勝者が見つかったときに設定される</param>
	/// <returns>勝者が存在する場合は true、存在しない場合は false。</returns>
	bool CheckWin(Mark& out_winner) const;

	/// <summary>
	/// 盤面が9マスとも埋まっているかチェック
	/// </summary>
	/// <returns>埋まっていたらTRUE</returns>
	bool IsBoardFull() const;

public:

	WinChecker(Grid* arg_grid);

	GameState CheckFinish(Mark& out_winner);

};
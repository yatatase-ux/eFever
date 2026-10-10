#include "WinChecker.h"

// 1本のラインを表す構造体
// 3マス分、それぞれ{row, col}のペアを持たせる
struct WinLine
{
	int cells[3][2]; // [0]=1マス目, [1]=2マス目, [2]=3マス目。各要素は{row, col}
};

// 8本のライン一覧(横3・縦3・斜め2)
/*-------------------------
  | {0,0} | {0,1} | {0,2} |
  |-------|-------|-------|
  | {1,0} | {1,1} | {1,2} |
  |-------|-------|-------|
  | {2,0} | {2,1} | {2,2} |
  -------------------------*/
const WinLine winLines[8] =
{
	// 横方向(rowを固定して、colだけ0→1→2と動かす)
	{ {{0,0}, {0,1}, {0,2}} }, // 上段
	{ {{1,0}, {1,1}, {1,2}} }, // 中段
	{ {{2,0}, {2,1}, {2,2}} }, // 下段

	// 縦方向(colを固定して、rowだけ0→1→2と動かす)
	{ {{0,0}, {1,0}, {2,0}} }, // 左列
	{ {{0,1}, {1,1}, {2,1}} }, // 中列
	{ {{0,2}, {1,2}, {2,2}} }, // 右列

	// 斜め方向
	{ {{0,0}, {1,1}, {2,2}} }, // 左上→右下
	{ {{0,2}, {1,1}, {2,0}} }, // 右上→左下
};

WinChecker::WinChecker(Grid* arg_grid)
	:grid(arg_grid)
{

}

GameState WinChecker::CheckFinish(Mark& out_winner)
{
	bool maruWin = false;	// ○が揃っているか
	bool batuWin = false;	// ×が揃っているか

	// 全ラインを調べて、○と×それぞれが揃っているか確認する
	CheckWin(maruWin, batuWin);

	// 演出の結果、○と×が同時に揃った場合は引き分け
	if (maruWin && batuWin)
	{
		out_winner = Mark::None;	// 勝者なし
		return GameState::Draw;
	}

	// ○だけ揃っている
	if (maruWin)
	{
		out_winner = Mark::Circle;
		return GameState::Win;
	}

	// ×だけ揃っている
	if (batuWin)
	{
		out_winner = Mark::Cross;
		return GameState::Win;
	}

	// 勝者がいなければ、盤面が埋まっているか確認する
	if (IsBoardFull())
	{
		return GameState::Draw;
	}

	// どちらでもなければ、まだゲーム継続中
	return GameState::InProgress;
}

// 全ラインを調べて、○と×それぞれが揃っているかを out 引数に入れる
void WinChecker::CheckWin(bool& out_maruWin, bool& out_batuWin) const
{
	for (int i = 0; i < 8; ++i)
	{
		const WinLine& line = winLines[i];

		// 1マス目の状態を基準として取得する
		Mark first = grid->GetCellMark(line.cells[0][0], line.cells[0][1]);

		// 1マス目が空なら、このラインは揃いようがないので次へ
		if (first == Mark::None)
		{
			continue;
		}

		// 2マス目・3マス目が、1マス目と同じかどうか確認する
		bool allSame = true;
		for (int j = 1; j < 3; ++j)
		{
			if (grid->GetCellMark(line.cells[j][0], line.cells[j][1]) != first)
			{
				allSame = false;
				break;
			}
		}

		// 3マス揃っていたら、そのマークの勝ちフラグを立てる
		// ※ここで return しないのがポイント(残りのラインも調べる)
		if (allSame)
		{
			if (first == Mark::Circle)
			{
				out_maruWin = true;
			}
			else if (first == Mark::Cross)
			{
				out_batuWin = true;
			}
		}
	}
}

/// <summary>
/// 盤面が9マスとも埋まっているかチェック
/// </summary>
bool WinChecker::IsBoardFull() const
{
	int filledCount = 0; // 埋まっているマスの数を数える変数

	for (int h = 0; h < 3; h++)
	{
		for (int w = 0; w < 3; w++)
		{
			// このマスの状態(空/○/×)を取得する
			Mark mark = grid->GetCellMark(h, w);

			// マークが入っていれば(空でなければ)カウントする
			if (mark != Mark::None)
			{
				filledCount++;
			}
		}
	}

	// 9マス(3×3)すべて埋まっていればtrue
	return (filledCount == 9);
}
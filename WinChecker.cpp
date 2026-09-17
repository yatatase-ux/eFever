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
	// まず勝者がいるか確認する(以前作った8ライン総当たりの処理)
	if (CheckWin(out_winner))
	{
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

bool WinChecker::CheckWin(Mark& out_winner) const
{
	for (int i = 0; i < 8; ++i)
	{
		const WinLine& line = winLines[i];

		// 1マス目の状態を基準として取得する
		// 基準のマスとは winLines の一番左に書いてあるマス（詳しくは上に書いてる F12で確認）
		int row0 = line.cells[0][0];
		int col0 = line.cells[0][1];
		Mark first = grid->GetCellMark(row0, col0);	// 基準のマーク

		// 1マス目が空なら、このラインは揃いようがないので次へ
		if (first == Mark::None)
		{
			continue;
		}

		// 2マス目・3マス目が、1マス目と同じ状態かどうかを確認する
		bool allSame = true;
		for (int j = 1; j < 3; ++j)
		{
			int row = line.cells[j][0];
			int col = line.cells[j][1];

			// 基準のマスと同じマークでなければ
			if (grid->GetCellMark(row, col) != first)
			{
				allSame = false;	// フラッグをFlaseにしてループを抜ける
				break;
			}

			// 2マス目3マス目が基準のマークと同じマークであればフラッグはTrueのままループを抜ける
		}

		// 3マスとも同じ状態だった場合、勝者を確定する
		if (allSame)
		{
			out_winner = first;		// 勝者のマークをout_winnerに入れる
			return true;
		}

		// 次の列・行を見る
	}

	return false; // 揃っているラインがなければ、まだ決着していない
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
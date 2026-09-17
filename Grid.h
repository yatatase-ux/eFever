#pragma once
#include <memory>
#include "Float2.h"
#include "Int2.h"
#include "Cell.h"
#include "WindowSize.h"
#include "KeyAction.h"
#include "TurnEnum.h"

class Grid
{
private:
	Float2 gridPos;
	Float2 gridSize;

	Cell cells[3][3];

public:

	Grid();

	void Input();
	bool Update();
	void Draw(Int2 selectCell);

	/// <summary>
	/// 指定したセルにマークを設定
	/// </summary>
	/// <param name="now">現在どちらのターンか</param>
	/// <param name="selectCell">どのセルか</param>
	/// <returns>指定したセルにマークが入っていればTRUE、空であればマークを設定しFALSEを返す</returns>
	bool SetMark(Turn now, Int2 selectCell);

	/// <summary>
	/// マスにマークが入っていればTRUEを返す関数
	/// </summary>
	/// <param name="row"></param>
	/// <param name="col"></param>
	/// <returns></returns>
	bool CheckCellMark(int row, int col) { return cells[row][col].CheckNoMark(); };
};
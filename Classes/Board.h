#pragma once
#include "Header.h"

class GridPos;

class Board
{
	unique_ptr<GridPos> _gridPos;

public:
	Board();
	Board(const int& row, const int& col);
	void init(const int& row, const int& col);
	void initGrid(const int& row, const int& col);

};
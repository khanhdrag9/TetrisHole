#include "Grid.h"

GridPos::GridPos()
{
}

GridPos::GridPos(const int& row, const int& col)
{
	init(row, col);
}

void GridPos::init(const int& row, const int& col)
{
	_sizePos = pos(row, col);

	_grid.clear();

	std::vector<Vec2> grid;
	grid.resize(_sizePos.col, Vec2(0, 0));
	_grid.resize(_sizePos.row, grid);
}

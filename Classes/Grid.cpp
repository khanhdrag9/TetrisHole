#include "Grid.h"


GridPosition::GridPosition(const int &row, const int &col)
{
    init(row, col);
}

void GridPosition::init(const int &row, const int &col)
{
    _size.row = row;
    _size.col = col;
    
    _grid.clear();
    
    for(int r = 0; r < row; ++r)
    {
        for(int c = 0; c < col; ++c)
        {
            _grid[pos(r,c)] = Vec2();
        }
    }
}


GridPosition::~GridPosition()
{ 
    _grid.clear();
}


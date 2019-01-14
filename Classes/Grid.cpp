#include "Grid.h"

Grid::Grid(const int &row, const int &col)
{
}

//Grid Position
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


//Grid Obj
void GridObj::init(const int &row, const int &col)
{
    _size.row = row;
    _size.col = col;
    
    _grid.clear();
    
    for(int r = 0; r < row; ++r)
    {
        for(int c = 0; c < col; ++c)
        {
            _grid[pos(r,c)] = nullptr;
        }
    };
}

shared_ptr<Obj>& GridObj::getObj(const pos& p){
    return _grid[p];
}

GridObj::~GridObj()
{ 
    _grid.clear();
}


GridObj::GridObj(const int &row, const int &col) { 
    init(row, col);
}

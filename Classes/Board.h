#pragma once
#include "Header.h"

class GridPosition;

class Board
{
public:
    static unique_ptr<GridPosition> gridPos;
    static float sideObj;
    
public:
    Board(const int& row, const int& col);
    ~Board();
    
    void init(const int& row, const int& col);
    
};

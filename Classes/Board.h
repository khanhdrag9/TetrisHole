#pragma once
#include "Header.h"

class GridPosition;
class GridObj;

class Board
{
public:
    static unique_ptr<GridPosition> gridPos;
    static unique_ptr<GridObj> girdObj;
    static float sideObj;
    
public:
    Board(const int& row, const int& col);
    ~Board();
    
    void init(const int& row, const int& col);
    
};

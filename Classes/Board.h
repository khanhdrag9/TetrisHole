#pragma once
#include "Header.h"

class GridPosition;

class Board
{
public:
    static unique_ptr<GridPosition> gridPos;
    
private:
    float _sideObj;
    
public:
    Board(const int& row, const int& col);
    ~Board();
    
    void init(const int& row, const int& col);
    
    inline const float& getSideObj()const{return _sideObj;}
    
};

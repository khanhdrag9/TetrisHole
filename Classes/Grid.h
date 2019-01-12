#pragma once
#include "Header.h"

class GridPosition
{
    map<pos, Vec2> _grid;
    pos _size;
public:
    GridPosition(const int& row, const int& col);
    ~GridPosition();
    
    void init(const int& row, const int& col);
    
    inline Vec2& realPos(const pos& p){
        
        return _grid[p];
    }
    //inline const pos& operator[](const Vec2& p) const{}
    inline const pos& getSize(){return _size;}
};

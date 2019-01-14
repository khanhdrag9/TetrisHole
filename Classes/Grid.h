#pragma once
#include "Header.h"

class Obj;

class Grid
{
protected:
    pos _size;
    
public:
    Grid(){}
    Grid(const int& row, const int& col);
    virtual ~Grid(){}
    
    virtual void init(const int& row, const int& col) = 0;
    inline const pos& getSize(){return _size;}
};

class GridPosition : public Grid
{
    map<pos, Vec2> _grid;
public:
    GridPosition(const int& row, const int& col);
    ~GridPosition();
    
    void init(const int& row, const int& col) override;
    
    inline Vec2& realPos(const pos& p){
        return _grid[p];
    }
    //inline const pos& operator[](const Vec2& p) const{}
};

class GridObj : public Grid
{
    map<pos, shared_ptr<Obj>> _grid;
public:
    GridObj(const int& row, const int& col);
    ~GridObj();
    
    void init(const int& row, const int& col) override;
    
    inline shared_ptr<Obj> getObj(const pos& p){
        return _grid[p];
    }

};

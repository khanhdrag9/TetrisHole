//
//  Board.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/12/19.
//

#include "Board.h"
#include "Templates.h"
#include "Grid.h"

unique_ptr<GridPosition> Board::gridPos = nullptr;

void Board::init(const int &row, const int &col)
{
    if(gridPos)
    {
        gridPos = nullptr;
    }
    
    Board::gridPos = make_unique<GridPosition>(row, col);
    
    //set Vec2 for girdPosition
    auto sz = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    {
        float sizeForW = sz.width / col;
        float sizeForH = sz.height / row;
        _sideObj = sizeForW < sizeForH ? sizeForW : sizeForH;
    }
    float rangeX = (sz.width - _sideObj * COL) / 2.f;   //ranger from side
    float rangeY = (sz.height - _sideObj * ROW) / 2.f;
    
    float startX = origin.x + rangeX + _sideObj * 0.5f;
    float startY = origin.y + rangeY + _sideObj * 0.5f;
    
    float px = startX;
    float py = startY;
    
    //set to grid
    for(int r = 0; r < row; ++r)
    {
        for(int c = 0; c < col; ++c)
        {
            Board::gridPos->realPos(pos(r,c)) = Vec2(px, py);
            px += _sideObj;
        }
        px = startX;
        py += _sideObj;
    }
}


Board::~Board()
{
}


Board::Board(const int &row, const int &col) { 
    init(row, col);
}

#pragma once
#include "Header.h"
#include "Board.h"
#include "Grid.h"

class Board;

class Obj
{
    pos _position;
public:
    Obj(const char* path);
    virtual ~Obj();
    
    Sprite* sprite;
    
    inline void setPosition(const pos& p)
    {
        _position = p;
        Vec2 realPos = Board::gridPos->realPos(_position);
        sprite->setPosition(realPos);
    }
    inline const pos& getPosition() const
    {
        return _position;
    }
};

#pragma once
#include "Header.h"
#include "Board.h"
#include "Grid.h"

class Board;

class Obj : public enable_shared_from_this<Obj>
{
    pos _position;
public:
    Obj(const char* path);
    virtual ~Obj();
    
    Sprite* sprite;
    
    inline void setPosition(const pos& p)
    {
        if(_position.row > -1 && _position.col > -1)
        {
            Board::girdObj->getObj(_position) = nullptr;
            Board::girdObj->getObj(p) = shared_from_this();
            
            _position = p;
            Vec2 realPos = Board::gridPos->realPos(_position);
            sprite->setPosition(realPos);
        }
    }
    inline const pos& getPosition() const
    {
        return _position;
    }
};

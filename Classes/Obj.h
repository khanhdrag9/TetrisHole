#pragma once
#include "Header.h"
#include "Board.h"
#include "Grid.h"

class Board;

class Obj : public enable_shared_from_this<Obj>
{
public:
    enum class Color : int
    {
        BLUE,
        RED,
        YELLOW
    };
    
protected:
	pos _position;
    Color _color;
    
public:
    Obj(const char* path, Color color);
    virtual ~Obj();
    
    Sprite* sprite;
    
    inline void setPosition(const pos& p, bool useRealPos)   //only available when not in hole
    {
        if(_position.row > -1 && _position.col > -1)
        {
            //Board::girdObj->getObj(_position) = nullptr;
            Board::girdObj->getObj(p) = shared_from_this();
            
            if(useRealPos)
            {
                Vec2 increRealPos = Board::gridPos->realPos(p) - Board::gridPos->realPos(_position);
                //Vec2 realPos = Board::gridPos->realPos(_position);
                Vec2 realPos = sprite->getPosition() + increRealPos;
                sprite->setPosition(realPos);
            }
            
            _position = p;
        }
    }
    inline const pos& getPosition() const
    {
        return _position;
    }
    inline const Color& getColor() const
    {
        return _color;
    }
};

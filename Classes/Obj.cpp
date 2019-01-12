//
//  Obj.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/12/19.
//

#include "Obj.h"
#include "Board.h"
#include "Grid.h"

inline const pos &Obj::getPosition() const
{
    return _position;
}

inline void Obj::setPosition(const pos &p)
{
    _position = p;
    Vec2 realPos = Board::gridPos->realPos(_position);
    sprite->setPosition(realPos);
}


Obj::Obj(const char *path)
{
    sprite = Sprite::create(path);
    sprite->retain();
}

Obj::~Obj()
{
    CC_SAFE_DELETE(sprite);
}

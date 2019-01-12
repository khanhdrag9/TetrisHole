//
//  Obj.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/12/19.
//

#include "Obj.h"


inline const pos &Obj::getPosition() const
{
    return _position;
}

inline void Obj::setPosition(const pos &p, const shared_ptr<Board>& board)
{
    _position = p;
    
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

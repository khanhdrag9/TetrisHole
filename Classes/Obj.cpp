//
//  Obj.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/12/19.
//

#include "Obj.h"


Obj::Obj(const char *path):_position(pos(0, 0))
{
    sprite = Sprite::create(path);
    sprite->retain();
}

Obj::~Obj()
{
    CC_SAFE_DELETE(sprite);
}

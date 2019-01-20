//
//  Obj.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/12/19.
//

#include "Obj.h"
#include "Board.h"
#include "Grid.h"

Obj::Obj(const char *path, Color color):
    _color(color)
{
    sprite = Sprite::createWithSpriteFrameName(path);
    sprite->retain();
}

Obj::~Obj()
{
    sprite->onExit();
    sprite->removeFromParentAndCleanup(true);
    CC_SAFE_DELETE(sprite);
}

void Obj::setPosition(const Vec2& p)   //only available when not in hole
{
    sprite->setPosition(p);
}

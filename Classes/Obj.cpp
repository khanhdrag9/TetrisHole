//
//  Obj.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/12/19.
//

#include "Obj.h"


Obj::Obj(const char *path, Color color):
    _position(pos(0, 0)),
    _color(color)
{
    sprite = Sprite::createWithSpriteFrameName(path);
    sprite->setPosition(Board::gridPos->realPos(_position));
    sprite->retain();
}

Obj::~Obj()
{
    sprite->onExit();
    sprite->removeFromParentAndCleanup(true);
    CC_SAFE_DELETE(sprite);
}

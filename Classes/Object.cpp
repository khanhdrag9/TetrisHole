#include "Object.h"
#include "Header.h"

gObject::gObject(const char* path)
{
    _sprite = Sprite::create(path);
}

gObject::gObject()
{
    
}

gObject::~gObject()
{
    
}

cocos2d::Sprite* gObject::getSprite()
{
    return _sprite;
}

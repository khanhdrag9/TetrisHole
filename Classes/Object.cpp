#include "Object.h"
#include "Header.h"

gObject::gObject(const char* path)
{
    _sprite = Sprite::create(path);
}

gObject::gObject()
{
    
}

gObject::gObject(shared_ptr<gObject> obj)
{
    _sprite = obj->_sprite;
}

gObject::~gObject()
{
    CC_SAFE_DELETE(_sprite);
}

cocos2d::Sprite* gObject::getSprite()
{
    return _sprite;
}

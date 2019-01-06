#include "Object.h"
#include "Header.h"

gObject::gObject(const char* path):
_status(status::MOVING)
{
    _sprite = Sprite::create(path);
}

gObject::gObject():
_status(status::MOVING)
{
    
}

gObject::gObject(shared_ptr<gObject> obj):
_status(status::MOVING)
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

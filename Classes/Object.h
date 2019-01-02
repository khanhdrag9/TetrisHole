#pragma once
#include "cocos2d.h"

class gObject
{
    
protected:
    cocos2d::Sprite* _sprite;
    
    gObject(const char* path);
public:
    gObject();
    virtual ~gObject();
    cocos2d::Sprite* getSprite();
  
    
    friend class ResourcesManager;
};

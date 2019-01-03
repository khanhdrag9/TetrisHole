#pragma once
#include "cocos2d.h"

class gObject
{
    
protected:
    cocos2d::Sprite* _sprite;
    
public:
    gObject();
	gObject(const char* path);

    virtual ~gObject();
    cocos2d::Sprite* getSprite();
  
    
    friend class ResourcesManager;
};

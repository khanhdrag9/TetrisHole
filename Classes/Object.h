#pragma once
#include "Header.h"

class gObject
{
    
protected:
    cocos2d::Sprite* _sprite;
    
public:
    gObject();
    gObject(shared_ptr<gObject> obj);
	gObject(const char* path);

    virtual ~gObject();
    cocos2d::Sprite* getSprite();
  
    
    friend class ResourcesManager;
    friend class GObjectManager;
};

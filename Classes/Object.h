#pragma once
#include "Header.h"

class gObject
{
    
protected:
    cocos2d::Sprite* _sprite;
    
public:
    enum class status
    {
        NONE,
        COLLISION,
        MOVING
    };
    
    gObject();
    gObject(shared_ptr<gObject> obj);
	gObject(const char* path);
    CC_SYNTHESIZE(status, _status, Status);

    virtual ~gObject();
    cocos2d::Sprite* getSprite();
  
    
    friend class ResourcesManager;
    friend class GObjectManager;
};

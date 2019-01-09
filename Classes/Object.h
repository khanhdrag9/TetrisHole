#pragma once
#include "Header.h"

class Board;

class gObject
{
 
protected:
    cocos2d::Sprite* _sprite;
    bool _inContain;
    bool _inHole;
    
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
	void setPosition(const pos& p, const shared_ptr<Board>& board);
	pos getPosition() const { return _pos; }
	Vec2 getRealPosition() const { return _sprite->getPosition(); }
    
    friend class ResourcesManager;
    friend class GObjectManager;
    friend class Suck;
    friend class Hole;
    friend class Skill;

public:
	pos _pos;
};

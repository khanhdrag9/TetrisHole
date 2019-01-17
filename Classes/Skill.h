#pragma once
#include "Header.h"

class Hole;

class Skill
{
    int _speed;
public:
	Skill();
	virtual ~Skill();
    
    virtual void update(Hole& hole, float dt);
};

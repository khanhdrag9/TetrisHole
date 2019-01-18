#pragma once
#include "Header.h"

class Hole;

class Skill
{
    int _speed;
public:
	Skill();
	virtual ~Skill();
	void setSpeed(const int& speed);
    
    virtual void update(Hole& hole, float dt);
};

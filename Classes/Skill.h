#pragma once
#include "Header.h"

class Board;
class Hole;

class Skill
{
protected:
    mutex mtx;
    shared_ptr<Hole> _hole;
    
    Skill(){}
    Skill(const shared_ptr<Hole> hole);
    
public:
    virtual ~Skill();
    
    virtual void use(float dt);
    virtual void active(void* value);
};

class Suck : public Skill
{
    float _speed;
public:
    Suck(){}
    Suck(const shared_ptr<Hole>& hole) : Skill(hole){}
	void use(float dt) override;
    void active(void* value) override;
};

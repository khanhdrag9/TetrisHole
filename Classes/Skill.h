#pragma once
#include "Header.h"

class Board;
class Hole;

class Skill
{
protected:
    shared_ptr<Hole> _hole;
    
    Skill(){}
    Skill(const shared_ptr<Hole> hole);
    
public:
    virtual ~Skill();
    
    virtual void use();
};

class Suck : public Skill
{
    
public:
    Suck(){}
    Suck(const shared_ptr<Hole>& hole) : Skill(hole){}
	void use() override;
};

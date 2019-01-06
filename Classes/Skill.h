#pragma once
#include "Header.h"

class Board;
class Hole;

class Skill
{
protected:
    mutex mtx;
    shared_ptr<Hole> _hole;
    std::function<void()> _callback = nullptr;
    bool _canCB = true;
    
    
    Skill(){}
    Skill(const shared_ptr<Hole> hole, std::function<void()> callback = nullptr);
    
public:
    virtual ~Skill();
    
    void setCallBack(std::function<void()> func){ _callback = func;}
    virtual void use(float dt);
    virtual void active(void* value);

};

class Suck : public Skill
{
    float _speed;
public:
    Suck(){}
    Suck(const shared_ptr<Hole>& hole, std::function<void()> callback = nullptr) : Skill(hole, callback){}
	void use(float dt) override;
    void active(void* value) override;
    bool hasFinished();
};

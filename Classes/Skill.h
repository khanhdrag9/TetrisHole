#pragma once
#include "Header.h"

class Board;
class Hole;
class gObject;

class Skill
{
protected:
    mutex mtx;
    shared_ptr<Hole> _hole;
    std::function<void()> _callback = nullptr;
    bool _canCB = true;
    float _interval;
    float _counttime;
    
    Skill(){}
    Skill(const shared_ptr<Hole> hole, std::function<void()> callback = nullptr);
    
public:
    virtual ~Skill();
    
    void setCallBack(std::function<void()> func){ _callback = func;}
    void setInterval(const float& value){ _interval = value; }
    virtual void use(float dt);
    virtual void active(void* value);

};

class Suck : public Skill
{
    int _speed = 1;
    void drop(shared_ptr<gObject> obj, bool upto);
    void slide(shared_ptr<gObject> obj, bool left);
public:
    Suck(){}
    Suck(const shared_ptr<Hole>& hole, std::function<void()> callback = nullptr) : Skill(hole, callback){}
	void use(float dt) override;
    void active(void* value) override;
    bool hasFinished();
};

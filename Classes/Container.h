#pragma once
#include "Header.h"

class Obj;

class Container
{
    
protected:
    vector<shared_ptr<Obj>> _objs;
    
public:
    Container(const int& number);
    virtual ~Container();
    
    void init(const int& number);
    void release();
    
    void setPosition(const pos& p);
	const Vec2& getPosition() const;
    
    inline vector<shared_ptr<Obj>>& getObjs() { return _objs; }
    inline int getNumberObjs() {return (int)_objs.size();}
    
public:
    Node* _node;
};

#pragma once
#include "Header.h"
#include "Object.h"

class gObject;

class Container
{
protected:
    shared_ptr<gObject> _object;
    
public:
    Container();
    Container(const shared_ptr<gObject>& obj);
    virtual ~Container();
    
    shared_ptr<gObject>& getObject(){return _object;}
};

class Circle : public Container
{
public:
    Circle();
    Circle(const shared_ptr<gObject>& obj);
    ~Circle();
    
    
    friend class GObjectManager;
};

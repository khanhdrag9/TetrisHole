#pragma once
#include "Header.h"

class Circle;
class Container;
class gObject;

class GObjectManager
{
    shared_ptr<Circle> _releaseCir;
    
public:
    GObjectManager();
    virtual ~GObjectManager();
    
    void init();
    
    shared_ptr<Circle> createCircle();
    void setPositionForObject(shared_ptr<gObject>& obj, Vec2& pos);
    void setPositionForContainer(shared_ptr<Container>& ctn, Vec2& pos);
    
};

//
//  GObjectManager.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/5/19.
//

#include "GObjectManager.h"
#include "ResourcesManager.h"
#include "Circle.h"

GObjectManager::GObjectManager():
    _releaseCir(nullptr)
{
    
}

GObjectManager::~GObjectManager()
{
    _releaseCir = nullptr;
}

void GObjectManager::init()
{
    
}

shared_ptr<Circle> GObjectManager::createCircle()
{
    _releaseCir = nullptr;
    shared_ptr<gObject> obj = ResourcesManager::getInstance()->getObject(object::CIRCLE);
    _releaseCir = make_shared<Circle>(obj);
    
    return _releaseCir;
}

void GObjectManager::setPositionForObject(shared_ptr<gObject>& obj, Vec2& pos)
{
    if(obj && obj->getSprite())
    {
        obj->getSprite()->setPosition(pos);
    }
}

void GObjectManager::setPositionForContainer(shared_ptr<Container>& ctn, Vec2& pos)
{
    if(ctn && ctn->getObject() && ctn->getObject()->getSprite())
    {
        ctn->getObject()->getSprite()->setPosition(pos);
    }
}

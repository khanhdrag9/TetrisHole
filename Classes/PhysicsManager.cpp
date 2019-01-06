//
//  PhysicsManager.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/6/19.
//

#include "PhysicsManager.h"
#include "Object.h"


PhysicsManager::PhysicsManager(PhysicsWorld* world):
    _physWorld(world)
{
    setting();
}

PhysicsManager::~PhysicsManager()
{
    _physWorld = nullptr;
}

void PhysicsManager::setting()
{
    
}

void PhysicsManager::addPhysicsForObject(const shared_ptr<gObject>& obj, bool dynamic, shape type)
{
    //auto sizeObj = obj->getSprite()->getBoundingBox().size;
    auto sizeObj = obj->getSprite()->getContentSize();
    PhysicsBody* body;
    
    if(type == shape::CIRCLE)
    {
        body = PhysicsBody::createCircle(sizeObj.width * 0.5f, PHYSICSBODY_MATERIAL_DEFAULT);
        
    }
    //more shape...
    else
    {
        body = PhysicsBody::createCircle(sizeObj.width * 0.5f);
    }
    
    if(body)
    {
        obj->getSprite()->addComponent(body);
        body->setDynamic(dynamic);
    }
}

bool PhysicsManager::onContactBegin(PhysicsContact& contact)
{
    
}

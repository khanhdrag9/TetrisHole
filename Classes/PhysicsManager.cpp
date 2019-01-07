//
//  PhysicsManager.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/6/19.
//

#include "PhysicsManager.h"
#include "Object.h"
#include "Board.h"


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
    _physWorld->setGravity(Vec2(0.f, 0.f));
}

int a = 1;

void PhysicsManager::addPhysicsForObject(const shared_ptr<gObject>& obj, bool dynamic, shape type)
{
    //auto sizeObj = obj->getSprite()->getBoundingBox().size;
    auto sizeObj = obj->getSprite()->getContentSize();
    PhysicsBody* body;
    
    if(type == shape::CIRCLE)
    {
        body = PhysicsBody::createCircle(sizeObj.width * 0.5f, PhysicsMaterial(0.f, 0.f, 0.f));
    
    }
    //more shape...
    else
    {
        body = PhysicsBody::createCircle(sizeObj.width * 0.5f);
    }
    
    if(body)
    {
        body->setContactTestBitmask(0xFFFFFFFF);
        body->setCollisionBitmask(true);
        
        obj->getSprite()->addComponent(body);
        body->setDynamic(dynamic);
    }
}

bool PhysicsManager::onContactBegin(PhysicsContact& contact, shared_ptr<Board>& board, int& flag1, int& flag2, function<void(list<gObject>)> callback)
{
    flag1 = contact.getShapeA()->getBody()->getNode()->getTag();
    flag2 = contact.getShapeB()->getBody()->getNode()->getTag();
    
    if(flag1 >= 0)
    {
        board->getListObjects()[flag1]->setStatus(gObject::status::COLLISION);
    }
    if(flag2 >= 0)
    {
        board->getListObjects()[flag2]->setStatus(gObject::status::COLLISION);
    }

	if (callback && flag1 >= 0 && flag2 >= 0)
	{
		list<gObject> listObj = { board->getListObjects()[flag1], board->getListObjects()[flag2] };
		callback(listObj);
	}
    
    return true;
}

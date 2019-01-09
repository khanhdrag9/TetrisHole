//
//  PhysicsManager.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/6/19.
//

#include "PhysicsManager.h"
#include "Object.h"
#include "Board.h"


PhysicsManager::PhysicsManager()
{
    setting();
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::setting()
{
   
}

CollisionType PhysicsManager::checkCollision(const shared_ptr<gObject>& obj, const shared_ptr<Board>& board)
{
	return CollisionType::NONE;
}

//
//  ResourcesManager.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/2/19.
//

#include "ResourcesManager.h"
#include "Object.h"

ResourcesManager::ResourcesManager()
{
   
}

ResourcesManager::~ResourcesManager()
{
    
}

shared_ptr<gObject> ResourcesManager::getObject()
{
    shared_ptr<gObject> obj = make_shared<gObject>("Square.png");
    
    
    return obj;
}
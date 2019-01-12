//
//  ContainerManager.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/12/19.
//

#include "ContainerManager.h"


ContainerManager::ContainerManager()
{
}

ContainerManager::~ContainerManager()
{
}


void ContainerManager::collectContainer(list<shared_ptr<Container>> &containers)
{
    while(containers.size() > 0)
    {
        _containers.push_back(*containers.begin());
        containers.pop_front();
    }
}

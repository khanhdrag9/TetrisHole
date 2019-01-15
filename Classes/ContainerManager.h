#pragma once
#include "Header.h"

class Container;

class ContainerManager
{
    vector<shared_ptr<Container>> _containers;
    
public:
    ContainerManager();
    ~ContainerManager();
    
    inline vector<shared_ptr<Container>>& getContainers(){
        return _containers;
    }
    void collectContainer(list<shared_ptr<Container>>& containers);
    
};

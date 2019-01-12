#pragma once
#include "Header.h"

class Container;

class CreateManager
{
public:
    CreateManager();
    ~CreateManager();
    
    shared_ptr<Container> createRandomContainer();
    
    
    enum class container_type : int
    {
        TWO = 2,
        THREE = 3,
    };
    
private:
    container_type getRandomContainerKey();
    shared_ptr<Container> createContainer(const container_type& type);
    
};

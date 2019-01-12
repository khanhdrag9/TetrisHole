#include "CreateManager.h"
#include "Container.h"

CreateManager::CreateManager()
{
    
}

CreateManager::~CreateManager()
{
    
}

shared_ptr<Container> CreateManager::createContainer(const CreateManager::container_type &type)
{
    return make_shared<Container>((int)type);
}


CreateManager::container_type CreateManager::getRandomContainerKey()
{
    container_type type;
    
    type = container_type::TWO;
    
    return type;
}


shared_ptr<Container> CreateManager::createRandomContainer()
{
    container_type key = getRandomContainerKey();
    return createContainer(key);
}


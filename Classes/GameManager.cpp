#include "GameManager.h"
#include "CreateManager.h"
#include "ContainerManager.h"
#include "Container.h"
#include "Obj.h"

GameManager::GameManager():
    _current(nullptr),
    _createMg(nullptr),
    _containerMg(nullptr)
{
    _screenSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    
    _createMg = make_unique<CreateManager>();
    _containerMg = make_unique<ContainerManager>();
}

GameManager::~GameManager()
{
    _current = nullptr;
    _createMg = nullptr;
    _containerMg = nullptr;
}

void GameManager::setNodeParrent(Node* node)
{
    _current = node;
}

void GameManager::createContainer()
{
    list<shared_ptr<Container>> list;
    
    //create a list with count the number of containers
    int count = 1;
    for(int i = 0; i < count; i++)
    {
        list.push_back(_createMg->createRandomContainer());
    }
    _containerMg->collectContainer(list);
    
    //add to scene
    for(auto& container : _containerMg->getContainers())
    {
        addChild(container);
    }
}

void GameManager::addChild(shared_ptr<Container> container)
{
    for(auto& o : container->getObjs())
    {
        _current->addChild(o->sprite);
    }
   
}

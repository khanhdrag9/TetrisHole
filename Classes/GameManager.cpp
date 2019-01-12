#include "GameManager.h"
#include "CreateManager.h"
#include "Container.h"
#include "Obj.h"

GameManager::GameManager():
    _parrent(nullptr),
    _createMg(nullptr)
{
    _createMg = make_unique<CreateManager>();
}

GameManager::~GameManager()
{
    _parrent = nullptr;
    _createMg = nullptr;
}

void GameManager::setNodeParrent(Node* node)
{
    _parrent = node;
}

void GameManager::createContainer()
{
    addChild(_createMg->createRandomContainer());
    
}

void GameManager::addChild(shared_ptr<Container> container)
{
    for(auto& o : container->getObjs())
    {
        _parrent->addChild(o->sprite);
        break;
    }
   
}

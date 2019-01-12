#include "GamePlay.h"
#include "GameManager.h"

Scene* GamePlay::createScene()
{
    auto scene = Scene::create();
    auto layer = GamePlay::create();
    scene->addChild(layer);
    return scene;
}

bool GamePlay::init()
{
    if(!Layer::init())
        return false;
    
    //init game manager
    GameManager::getInstance()->setNodeParrent(this);
    GameManager::getInstance()->createContainer();
    
    this->scheduleUpdate();
    return true;
}

void GamePlay::update(float dt)
{
    
}

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
   // GameManager::getInstance()->createContainer();
    
    //touch listener
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch* touch, Event* event){ return GameManager::getInstance()->touchBegan(touch, event);};
    listener->onTouchMoved = [this](Touch* touch, Event* event){ GameManager::getInstance()->touchMoved(touch, event);};
    listener->onTouchEnded = [this](Touch* touch, Event* event){ GameManager::getInstance()->touchEnded(touch, event);};
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->scheduleUpdate();
    return true;
}

void GamePlay::update(float dt)
{
	GameManager::getInstance()->update(dt);
}

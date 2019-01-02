#include "GamePlay.h"
#include "ResourcesManager.h"
#include "Square.h"

Scene* GamePlay::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = GamePlay::create();
    scene->addChild(layer);
    
    return scene;
}

bool GamePlay::init()
{
    if(!Layer::init())
        return false;
    
    auto a = ResourcesManager::getInstance()->getObject();
    this->addChild(a->getSprite());
    
    return true;
}

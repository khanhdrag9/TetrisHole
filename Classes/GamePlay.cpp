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
	a->getSprite()->setScale(0.3);
	a->getSprite()->setPosition(300, 500);
    this->addChild(a->getSprite());
    
    return true;
}

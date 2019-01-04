#include "GamePlay.h"
#include "ResourcesManager.h"
#include "Square.h"
#include "Board.h"
#include "Hole.h"

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
    

	initBoard();
	initSchedule();

    return true;
}

void GamePlay::update(float dt)
{
	if (_board) _board->update(dt);

}

void GamePlay::initBoard()
{
	_board = make_shared<Board>();
	_board->setHole(make_shared<Hole>());
	_board->setHoleSkill(skill::stuck);
}

void GamePlay::initSchedule()
{
	this->scheduleUpdate();
}
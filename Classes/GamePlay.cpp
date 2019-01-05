#include "GamePlay.h"
#include "ResourcesManager.h"
#include "GObjectManager.h"
#include "Board.h"
#include "Hole.h"
#include "Circle.h"
#include "Templates.h"

GamePlay::GamePlay():
    _board(nullptr),
    _objMgr(nullptr)
{
    
}

GamePlay::~GamePlay()
{
    _board = nullptr;
    _objMgr = nullptr;
}

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
    
    
    _screenSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();

	initBoard();
    initObjectStart();
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
    _board->setNode(this);

    _board->setHole(make_shared<Hole>());
    _board->setHoleSkill(skill::stuck);
}

void GamePlay::initObjectStart()
{
    _objMgr = make_unique<GObjectManager>();
    
    auto a = _objMgr->createCircle();
    a->getObject()->getSprite()->setScale(0.1);
    a->getObject()->getSprite()->setPosition(300, _screenSize.height - 100);
    _board->collectObject(a->getObject());


    auto hole = ResourcesManager::getInstance()->getObject(object::HOLE);
    hole->getSprite()->setScale(0.3);
    hole->getSprite()->setPosition(_screenSize.width / 2.f + _origin.x, _screenSize.height / 2.f + _origin.y);
    hole->getSprite()->runAction(RepeatForever::create(RotateBy::create(0.01, 10)));
    hole->getSprite()->setOpacity(75);
    _board->setRepresentHole(hole);

}

void GamePlay::initSchedule()
{
	this->scheduleUpdate();
}

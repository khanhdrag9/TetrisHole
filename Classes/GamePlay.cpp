#include "GamePlay.h"
#include "ResourcesManager.h"
#include "GObjectManager.h"
#include "Board.h"
#include "Hole.h"
#include "Circle.h"
#include "Templates.h"
#include "PhysicsManager.h"

GamePlay::GamePlay():
    _board(nullptr),
    _objMgr(nullptr),
    _phyMgr(nullptr),
    _isCreated(true)
{
    
}

GamePlay::~GamePlay()
{
    _board = nullptr;
    _objMgr = nullptr;
    _phyMgr = nullptr;
}

Scene* GamePlay::createScene()
{
    Scene* scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    GamePlay* layer = GamePlay::create();
    layer->initPhysicsWorldSetting(scene->getPhysicsWorld());
    
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
    initListeners();
    initSchedule();

    return true;
}

void GamePlay::update(float dt)
{
    if(_isCreated)
    {
        createCircle(true);
        
        _isCreated = false;
    }
    
	if (_board)
    {
        _board->update(dt);
    }

}

void GamePlay::initBoard()
{
	_board = make_shared<Board>();
    _board->setNode(this);

    _board->setHole(make_shared<Hole>());
    
    std::function<void()> cb = [this](){
		if(_board->getListObjects().size() <= 1)
			_isCreated = true;
    };
    _board->setHoleSkill(skill::stuck, cb);
}

void GamePlay::initPhysicsWorldSetting(PhysicsWorld* world)
{
    _phyMgr = make_unique<PhysicsManager>(world);
    
   // _phyMgr->addPhysicsForObject(_board->getRepresentHole(), false, shape::CIRCLE);
    
//    for(auto& obj : _board->getListObjects())
//    {
//        _phyMgr->addPhysicsForObject(obj, true, shape::CIRCLE);
//    }
    
    
}

void GamePlay::initObjectStart()
{
    _objMgr = make_unique<GObjectManager>();
    
    //createCircle(true);

    //init hole
    auto hole = ResourcesManager::getInstance()->getObject(object::HOLE);
    hole->getSprite()->setScale(0.3);
    hole->getSprite()->setPosition(_screenSize.width / 2.f + _origin.x, _screenSize.height / 2.f + _origin.y);
    hole->getSprite()->runAction(RepeatForever::create(RotateBy::create(0.01, 10)));
    hole->getSprite()->setOpacity(75);
    _board->setRepresentHole(hole);

}

void GamePlay::initListeners()
{
    auto physListener = EventListenerPhysicsContact::create();
    physListener->onContactBegin = [this](PhysicsContact& contact){
        
		int flag1, flag2;
        int result = _phyMgr->onContactBegin(contact, _board, flag1, flag2);

		int tagCurCir = _objMgr->getCurrentCirTag();
		if (flag1 == tagCurCir || flag2 == tagCurCir)
			_isCreated = true;

        return result;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(physListener, this);
}

void GamePlay::initSchedule()
{
	this->scheduleUpdate();
}


void GamePlay::createCircle(bool up)
{
    //set pos at down screen or up screen
    Vec2 pos = Vec2(_screenSize.width / 2.f + _origin.x, 0 + _origin.y);
    if(up) pos.y = _screenSize.height + _origin.y;
	CCLOG("Pos create : %f-%f", pos.x, pos.y);
    //calculate scale for resolution
    float scale = 0.1f;
    
    //create circle
    auto cir = _objMgr->createCircle();
    cir->getObject()->getSprite()->setScale(scale);
    cir->getObject()->getSprite()->setPosition(pos);
    _board->collectObject(cir->getObject());
    _phyMgr->addPhysicsForObject(cir->getObject(), true);
}

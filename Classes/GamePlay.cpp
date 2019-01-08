#include "GamePlay.h"
#include "ResourcesManager.h"
#include "GObjectManager.h"
#include "Board.h"
#include "Hole.h"
#include "Circle.h"
#include "Templates.h"
#include "PhysicsManager.h"
#include "Grid.h"

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
    Scene* scene = Scene::create();
    GamePlay* layer = GamePlay::create();
    
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
	_board = make_shared<Board>(ROW, COL);
    
#if ENABLE_DEBUG_GRID
    int i = 0;
    for (int r = 0; r < _board->getGridPos().sizePos().row; r++)
    {
        for (int c = 0; c < _board->getGridPos().sizePos().col; c++)
        {
            Vec2 pos = _board->getGridPos()[r][c];
            Label* t = Label::createWithTTF(to_string(i), FONT_ARIAL, 13);
            t->setPosition(_origin + pos);
            t->setColor(Color3B::YELLOW);
            this->addChild(t);
            //i++;
        }
    }
#endif
    
    _board->setNode(this);

    _board->setHole(make_shared<Hole>());
    
    std::function<void()> cb = [this](){
		if(_board->getListObjects().size() <= 1)	//for first circle
			_isCreated = true;
    };
    _board->setHoleSkill(skill::stuck, cb);

	//set position for layer
	Size boardSize = _board->getSize();
	Vec2 posLayer = Vec2(_screenSize.width - boardSize.width, _screenSize.height - boardSize.height) / 2.f;
	this->setPosition(posLayer + _origin);
}

void GamePlay::initObjectStart()
{
    _objMgr = make_unique<GObjectManager>();
    
    //createCircle(true);

    //init hole

}

void GamePlay::initListeners()
{
    
}

void GamePlay::initSchedule()
{
	this->scheduleUpdate();
}


void GamePlay::createCircle(bool up)
{
    //set pos at down screen or up screen
    Vec2 pos;
    //calculate scale for resolution
    float scale = 0.1f;
    
    //create circle
    
}

void GamePlay::deleteCircle(list<gObject> listObj)
{
	CCLOG("Delelte Circle");
}

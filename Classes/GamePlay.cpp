#include "GamePlay.h"
#include "ResourcesManager.h"
#include "GObjectManager.h"
#include "Board.h"
#include "Hole.h"
#include "Circle.h"
#include "Templates.h"
#include "PhysicsManager.h"
#include "Grid.h"

pos GamePlay::createUp = pos(ROW - 1, COL / 2);
pos GamePlay::createDown = pos(0, COL / 2);
pos GamePlay::center = pos(ROW / 2, COL / 2);

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
    _board->setNode(this);
    
    //set position for layer
    Size boardSize = _board->getSize();
    Vec2 posLayer = Vec2(_screenSize.width - boardSize.width, _screenSize.height - boardSize.height) / 2.f;
    this->setPosition(posLayer);
    
    //define up-center-
	pos colrows = _board->getRowCols();
	GamePlay::createUp = pos(colrows.row - 1, colrows.col / 2);
	GamePlay::createDown = pos(0, colrows.col / 2);
	GamePlay::center = pos(colrows.row / 2, colrows.col / 2);
    
#if ENABLE_DEBUG_GRID
    for (int r = 0; r < _board->getRowCols().row; r++)
    {
        for (int c = 0; c < _board->getRowCols().col; c++)
        {
            Vec2 pos = _board->getGridPos()[r][c];
			if (pos != Vec2(0, 0))
			{
				Label* t = Label::createWithTTF("o", FONT_ARIAL, _board->getSideBox() * 1.75f);
				t->setPosition(pos);
				t->setColor(Color3B::GRAY);
				t->setOpacity(75.f);
				this->addChild(t);
			}
            //i++;
        }
    }
#endif

	//hole
    _board->setHole(make_shared<Hole>());
    std::function<void()> cb = [this](){
		
    };
    _board->setHoleSkill(skill::stuck, cb);

	auto holeRepre = ResourcesManager::getInstance()->getObject(object::HOLE);
	holeRepre->getSprite()->setScale(0.2);
	_board->setRepresentHole(holeRepre);
	_board->setHolePos(GamePlay::center);
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
	pos posCreate = GamePlay::createUp;
	Vec2 realPos = _board->getGridPos()[posCreate.row][posCreate.col];
	
	//create circle
	auto cir = _objMgr->createCircle();
	auto sprite = cir->getObject()->getSprite();
	float scale = _board->getSideBox() / (float)(sprite->getContentSize().width);
	sprite->setScale(scale);
	sprite->setPosition(realPos);
    
	this->addChild(sprite);


	//for test
	Vec2 realPos2 = _board->getGridPos()[posCreate.row - 1][posCreate.col + 1];	//to test
	auto cir2 = _objMgr->createCircle();
	auto sprite2 = cir2->getObject()->getSprite();
	float scale2 = _board->getSideBox() / (float)(sprite2->getContentSize().width);
	sprite2->setScale(scale2);
	sprite2->setPosition(realPos2);

	this->addChild(sprite2);
}

void GamePlay::deleteCircle(list<gObject> listObj)
{
	CCLOG("Delelte Circle");
}

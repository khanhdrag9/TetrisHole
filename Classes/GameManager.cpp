#include "GameManager.h"
#include "CreateManager.h"
#include "ContainerManager.h"
#include "Board.h"
#include "Container.h"
#include "Obj.h"
#include "Grid.h"
#include "Hole.h"

GameManager::GameManager():
    _current(nullptr),
    _createMg(nullptr),
    _containerMg(nullptr),
	_createdContainer(false),
	_hole(nullptr),
	_count_time(0.f),
	_interval_time(0.15f),
    _holeDirect(direction::NONE)
{
    _screenSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    
    _board = make_unique<Board>(ROW, COL);

	//create pos to init a container on it
	pos size = Board::gridPos->getSize();
	_createTop = pos(size.row - 1, size.col / 2);
	_createBot = pos(0, size.col / 2);
	_axis = pos(size.row / 2, size.col / 2);
    
    _createMg = make_unique<CreateManager>();
    _containerMg = make_unique<ContainerManager>();
	_hole = make_unique<Hole>();

}

GameManager::~GameManager()
{
    _current = nullptr;
    _createMg = nullptr;
    _containerMg = nullptr;
    _board = nullptr;
	_hole = nullptr;
}

void GameManager::update(float dt)
{
	if (!_current)
	{
		//CCLOG("current is null");
		return;
	}
    
	//hole move
	if(_hole)
	{
		
	}
    

	//move container
	if (_count_time >= _interval_time)
	{
        vector<shared_ptr<Container>>::iterator it;
        for(it = _containerMg->getContainers().begin(); it != _containerMg->getContainers().end();)
		{
			if (*it)
			{
				auto listCol = getCollisionPos(*it);
                if(listCol[collision_pos::BOT] == true || listCol[collision_pos::AXIS] == true)
                {
                    _createdContainer = true;
					
					for (auto& o : (*it)->getObjs())	//add obj to hole
					{
						_hole->collect(o);
                        //_objsUnContainer.push_back(o);
                       
					}

                    it = _containerMg->getContainers().erase(it);   //delete from ContainerManager
                }
				else
                {
                    pos incre = pos(-1, 0);
                    moveByContainer(*it, incre);
                    it++;
                }
			}
            else
            {
                it++;
            }
            
		}
        
		_count_time = 0.f;
	}
	else
	{
		_count_time += dt;
	}


	if (_createdContainer)
	{
		createContainer();
		_createdContainer = false;
	}
}

void GameManager::moveByContainer(shared_ptr<Container> container, const pos& incre)
{
	//calculate new pos
	
}

void GameManager::moveByHole(const pos& incre)
{
    if(_hole)
    {
        _hole->setPosition(_hole->getPosition() + incre);
        
        /*for(auto& o : _objsUnContainer)
        {
            if(o)
            {
                pos newpos = o->getPosition() + incre;
                o->setPosition(newpos, false);
            }
        }*/
    }
    else
    {
        CCLOG("Hole is null, cannot move!");
    }
}

void GameManager::setNodeParrent(Node* node)
{
    _current = node;
	_hole->init(node);
    _hole->setPosition(_axis);
	Sprite* repre = Sprite::create(HOLE_REPRE);
	repre->setScale(0.2);
	_hole->setRepresent(repre);
	_hole->initSkill(true, 1);
    
#if ENABLE_DEBUG_GRID
    pos sizeBoard = Board::gridPos->getSize();
    for (int r = 0; r < sizeBoard.row; r++)
    {
        for (int c = 0; c < sizeBoard.col; c++)
        {
            Vec2 position = Board::gridPos->realPos(pos(r,c));
            if (position != Vec2(0, 0))
            {
                Label* t = Label::createWithTTF("o", FONT_ARIAL, Board::sideObj * 1.75f);
                t->setPosition(position);
                t->setColor(Color3B::GRAY);
                t->setOpacity(75.f);
                _current->addChild(t);
            }
        }
    }
#endif

	_createdContainer = true;
}

void GameManager::createContainer()
{
    list<shared_ptr<Container>> list;
    
    //create a list with count the number of containers
    int count = 1;
    for(int i = 0; i < count; i++)
    {
        auto container = _createMg->createRandomContainer();
		container->setPosition(_createTop);
        
        container->_node->runAction(MoveTo::create(5, Board::gridPos->realPos(_axis)));
        
		list.push_back(container);
    }

	//add to scene
	for (auto& container : list)
	{
		addChild(container);
	}

	//add to mgr
    _containerMg->collectContainer(list);
}

void GameManager::addChild(shared_ptr<Container> container)
{
	if (_current)
	{
//        for (auto& o : container->getObjs())
//        {
//            _current->addChild(o->sprite);
//        }
        _current->addChild(container->_node);
	}
	else
	{
		CCLOG("Current node is null");
	}
}

bool GameManager::checkPos(const pos& p)
{
    pos girdSize = Board::gridPos->getSize();
    
    if(p.row < 0 || p.row >= girdSize.row || p.col < 0 || p.col >= girdSize.col)
        return false;
    else
        return true;
}

//array<pos, collision_pos::HAS> getListToCheckCol(const pos& p)
vector<pos> getListToCheckCol(const pos& p)
{
   // array<pos, collision_pos::HAS> check = { //Order by collision_pos enum
    vector<pos> check = {
        pos(p.row + 1, p.col),  //Top
        pos(p.row - 1, p.col),  //Bot...
        pos(p.row, p.col - 1),
        pos(p.row, p.col + 1),
        pos(p.row + 1, p.col - 1),
        pos(p.row + 1, p.col + 1),
        pos(p.row - 1, p.col - 1),
        pos(p.row - 1, p.col + 1),
        pos(p.row, p.col)   //Axis
    };
    
    return check;
}

check_collision GameManager::getCollisionPos(const pos& p) const
{
    check_collision result;
	result.fill(false);
    
    auto check = getListToCheckCol(p);
    
    for(int i = 0; i < collision_pos::HAS; i++)
    {
        if(i == collision_pos::AXIS)
        {
            if(check[i].row == _axis.row)   //check special case - axis
            {
                result[i] = true;
            }
            continue;
        }
        
        if(Board::girdObj->getObj(check[i]))
            result[i] = true;
    }
    
    return result;
}

check_collision GameManager::getCollisionPos(const shared_ptr<Container>& container) const
{
	check_collision result;
	result.fill(false);
	
	for (auto& obj : container->getObjs())
	{
        
	}

	//check collision of contaienr
	for (auto& obj : container->getObjs())
	{
		
        
	}

	return result;
}

check_collision GameManager::getCollisionPos(const unique_ptr<Hole>& hole) const
{
	check_collision result;
	result.fill(false);

	for (auto& obj : hole->getObjs())
	{
		
	}

	//check of node itself
	{
		
	}

	//check collision of contaienr
	for (auto& obj : hole->getObjs())
	{
		
		
	}

	return result;
}

void GameManager::scan()
{
    
}

void GameManager::scanScore(const shared_ptr<Obj>& objstart, collision_pos direct, scan_direct_obj& beforeObjs)
{
    
}

void GameManager::deleteScoreObj(const pos& axisObjPos, scan_direct_obj& beforeObjs)
{
    
}

void GameManager::touchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
}

void GameManager::touchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if(_touchBegin == Vec2(0,0))
    {
        CCLOG("can specify touch begin when move touch");
        return;
    }
    
    Vec2 touchPos = touch->getLocation();
    float sub2Touch = touchPos.x - _touchBegin.x;
    if(abs((float)sub2Touch) >= Board::sideObj * 0.8f)
    {
        if(sub2Touch < 0)
        {
            _holeDirect = direction::LEFT;
        }
        else if(sub2Touch > 0)
        {
            _holeDirect = direction::RIGHT;
        }
        _touchBegin = touchPos;
    }
    
}

bool GameManager::touchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if(_hole)
    {
        _touchBegin = touch->getLocation();
        _rangerTouch = _touchBegin - Board::gridPos->realPos(_hole->getPosition());
    }
    return true;
}

scan_direct_obj GameManager::defaultScanDirectObj()
{
    scan_direct_obj sdo;
    
    for(int i = 0; i < collision_pos::HAS; i++)
    {
        sdo[(collision_pos)i] = list<pos>();
    }
    
    return sdo;
}

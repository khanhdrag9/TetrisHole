#include "GameManager.h"
#include "CreateManager.h"
#include "ContainerManager.h"
#include "Board.h"
#include "Container.h"
#include "Obj.h"
#include "Grid.h"

GameManager::GameManager():
    _current(nullptr),
    _createMg(nullptr),
    _containerMg(nullptr),
	_createdContainer(false),
	_count_time(0.f),
	_interval_time(0.3f)
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
    
}

GameManager::~GameManager()
{
    _current = nullptr;
    _createMg = nullptr;
    _containerMg = nullptr;
    _board = nullptr;
}

void GameManager::update(float dt)
{
	if (!_current)
	{
		//CCLOG("current is null");
		return;
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
                    it = _containerMg->getContainers().erase(it);
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
	pos newpos = container->getPosition();
	if (newpos.row < 0)
	{
		CCLOG("Curpos is not available!");
		return;
	}

	newpos = newpos + incre;
	container->setPosition(newpos);
}

void GameManager::setNodeParrent(Node* node)
{
    _current = node;
    
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
		for (auto& o : container->getObjs())
		{
			_current->addChild(o->sprite);
		}
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

check_collision GameManager::getCollisionPos(const pos& p) const
{
    check_collision result;
    
    pos check[] = {             //Order by collision_pos enum
        pos(p.row + 1, p.col),  //Top
        pos(p.row - 1, p.col),  //Bot...
        pos(p.row, p.col - 1),
        pos(p.row, p.col + 1),
        pos(p.row + 1, p.col - 1),
        pos(p.row + 1, p.col + 1),
        pos(p.row - 1, p.col - 1),
        pos(p.row - 1, p.col + 1),   //Bot_right
        pos(p.row - 1, p.col)   //Axis
    };
    
    for(int i = 0; i < collision_pos::HAS; i++)
    {
        if(Board::girdObj->getObj(check[i]))
            result[i] = true;
        else
            result[i] = false;
    }
    
    return result;
}

check_collision GameManager::getCollisionPos(const shared_ptr<Container>& container) const
{
	check_collision result;

	list<pos> posskips;	//skip Obj in same container
	for (auto& obj : container->getObjs())
	{
        if(obj)
            posskips.push_back(obj->getPosition());
	}

	//check collision of contaienr
	for (auto& obj : container->getObjs())
	{
		pos p = obj->getPosition();
		pos check[] = {
			pos(p.row + 1, p.col),
			pos(p.row - 1, p.col),
			pos(p.row, p.col - 1),
			pos(p.row, p.col + 1),
			pos(p.row + 1, p.col - 1),
			pos(p.row + 1, p.col + 1),
			pos(p.row - 1, p.col - 1),
			pos(p.row - 1, p.col + 1),
            pos(p.row - 1, p.col)
		};
        
        //check with Axis
		for (int i = 0; i < collision_pos::HAS; i++)    //skip check with Axis
		{
			pos poscheck = check[i];

            bool isContain = (std::find(posskips.begin(), posskips.end(), poscheck) != posskips.end());

			if (!isContain)
			{
                if(i == collision_pos::AXIS && poscheck.row == _axis.row)
                    result[i] = true;
                else if (Board::girdObj->getObj(poscheck))
                    result[i] = true;
                else
                    result[i] = false;
                
			}
		}
	}

	return result;
}

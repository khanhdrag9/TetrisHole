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
    _containerMg(nullptr)
{
    _screenSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    
    _board = make_unique<Board>(ROW, COL);
    
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
    
}

void GameManager::createContainer()
{
    list<shared_ptr<Container>> list;
    
    //create a list with count the number of containers
    int count = 1;
    for(int i = 0; i < count; i++)
    {
        list.push_back(_createMg->createRandomContainer());
    }
    _containerMg->collectContainer(list);
    
    //add to scene
    for(auto& container : _containerMg->getContainers())
    {
        addChild(container);
    }
}

void GameManager::addChild(shared_ptr<Container> container)
{
    for(auto& o : container->getObjs())
    {
        _current->addChild(o->sprite);
    }
   
}

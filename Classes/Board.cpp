#include "Board.h"
#include "Grid.h"
#include "Hole.h"
#include "Object.h"

Board::Board():
	_hole(nullptr),
    _parrentObject(nullptr),
    _representHole(nullptr)
{
}

Board::Board(const int& row, const int& col)
{
	init(row, col);
}

Board::~Board()
{
    CC_SAFE_DELETE(_parrentObject);
    _hole = nullptr;
    _representHole = nullptr;
}

void Board::init(const int& row, const int& col)
{
	Size sz = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	float side = sz.width > sz.height ? sz.width : sz.height;

	initGrid(row, col);

	//for position in gridPosition
	/*float startX = 0.f;
	float startY = 0.f;

	for (int r = 0; r < _gridPos->sizePos().row; r++)
	{
		for (int c = 0; c < _gridPos->sizePos().col; c++)
		{

		}
	}*/
}

void Board::initGrid(const int& row, const int& col)
{
	//for Grid Position
	//_gridPos = make_unique<GridPos>(row, col);

	
}

void Board::update(float dt)
{
	if (_hole)
    {
        _hole->useSkill();
    }

}

void Board::collectObject(const shared_ptr<gObject>& object)
{
	_listObject.push_back(object);
    if(_parrentObject)
        _parrentObject->addChild(object->getSprite());
}

void Board::setHole(const shared_ptr<Hole>& hole)
{
	_hole = hole;
	_hole->_boardParrent = shared_from_this();
}

void Board::setHoleSkill(skill typeSkill)
{
	if (_hole)_hole->setSkill(typeSkill);
}

void Board::setRepresentHole(const shared_ptr<gObject>& obj)
{
    if(_representHole)
    {
        _representHole->getSprite()->retain();
        _representHole->getSprite()->removeFromParentAndCleanup(true);
        _representHole->getSprite()->autorelease();
    }
    
    _representHole = obj;
    _parrentObject->addChild(_representHole->getSprite());
    _hole->_spriteNode->setPosition(_representHole->getSprite()->getPosition());
}

void Board::setNode(Node* node)
{
    //release all object from node
    if(_parrentObject)
    {
        for(auto& o : _listObject)
        {
            o->getSprite()->retain();
            o->getSprite()->removeFromParentAndCleanup(true);
            o->getSprite()->autorelease();
        }
        
        if(_representHole)
        {
            _representHole->getSprite()->retain();
            _representHole->getSprite()->removeFromParentAndCleanup(true);
            _representHole->getSprite()->autorelease();
        }
        
        if(_hole)
        {
            _hole->_spriteNode->retain();
            _hole->_spriteNode->removeFromParentAndCleanup(true);
            _hole->_spriteNode->autorelease();
        }
    }
    
    //set object to new node
    _parrentObject = node;
    for(auto& o : _listObject)
    {
        _parrentObject->addChild(o->getSprite());
    }
    
    if(_representHole)
    {
        _parrentObject->addChild(_representHole->getSprite());
    }
    
    if(_hole)
    {
        _parrentObject->addChild(_hole->_spriteNode);
    }
    
}

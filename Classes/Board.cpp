#include "Board.h"
#include "Hole.h"
#include "Skill.h"
#include "Object.h"

Board::Board():
	_hole(nullptr),
    _parrentObject(nullptr),
    _representHole(nullptr)
{
}

Board::Board(const int& row, const int& col):
_hole(nullptr),
_parrentObject(nullptr),
_representHole(nullptr)
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
 //   Size sz = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	initGrid(row, col);

	//for position in gridPosition
    {
        float sizeForW = float(sz.width) / (float)(col);
        float sizeForH = 2 * float(sz.height) / (float)(row);
        
        if(sizeForW < sizeForH)
        {
            _sideBox = sizeForW;
        }
        else if(sizeForW >= sizeForH)
        {
            _sideBox = sizeForH;
        }
    }
    _maxW = _sideBox * col;
    _maxH = _sideBox * row / 2.f;
    
    float increValueH = _sideBox / 2.f;
    float increValueW = _sideBox;
    
    float startX1 = _sideBox / 2.f;
    float startX2 = _sideBox;
    float px = startX1;
    
    float py = _sideBox / 2.f;

    for (int r = 0; r < _gridPos.sizePos().row; r++)
    {
        for (int c = 0; c < _gridPos.sizePos().col; c++)
        {
            _gridPos[r][c] = Vec2(px, py);
            px += increValueW;
        }
        py += increValueH;
        if(r%2==0)px = startX2;
        else px = startX1;
    }
    
}

void Board::initGrid(const int& row, const int& col)
{
	//for Grid Position
	_gridPos = GridPos(row, col);

	
}

void Board::update(float dt)
{
	if (_hole)
    {
        _hole->_skill->active(static_cast<void*>(new float(100.f)));
        _hole->useSkill(dt);
    }

}

void Board::collectObject(const shared_ptr<gObject>& object)
{
    object->getSprite()->setTag((int)_listObject.size());
	_listObject.push_back(object);
    
}

void Board::setHole(const shared_ptr<Hole>& hole)
{
	_hole = hole;
	_hole->_boardParrent = shared_from_this();
}

void Board::setHoleSkill(skill typeSkill, std::function<void()> callback)
{
	if (_hole)_hole->setSkill(typeSkill, callback);
}

void Board::setRepresentHole(const shared_ptr<gObject>& obj)
{
    
}

void Board::setNode(Node* node)
{
    
}

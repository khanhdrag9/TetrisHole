#include "Board.h"
#include "Grid.h"
#include "Hole.h"

Board::Board():
	_hole(nullptr)
{
}

Board::Board(const int& row, const int& col)
{
	init(row, col);
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
		_hole->useSkill();

}

void Board::collectObject(const shared_ptr<gObject>& object)
{
	_listObject.push_back(object);
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
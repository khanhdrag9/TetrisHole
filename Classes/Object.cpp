#include "Object.h"
#include "Board.h"

gObject::gObject(const char* path):
_status(status::MOVING),
_parrent(own::none)
{
    _sprite = Sprite::create(path);
}

gObject::gObject():
_status(status::MOVING),
_parrent(own::none)
{
    
}

gObject::gObject(shared_ptr<gObject> obj):
_status(status::MOVING),
_parrent(own::none)
{
    _sprite = obj->_sprite;
}

gObject::~gObject()
{
	_sprite = nullptr;
}

cocos2d::Sprite* gObject::getSprite()
{
    return _sprite;
}

void gObject::setPosition(const pos& p, const shared_ptr<Board>& board)
{
	pos rowcols = board->getRowCols();
	if (p.row < rowcols.row && p.row >= 0 && p.col < rowcols.col && p.col >= 0)
	{
		_pos = p;
		Vec2 realPos = board->getGridPos()[_pos.row][_pos.col];
		_sprite->setPosition(realPos);
	}
	else
	{
		CCLOG("gObjet set avaible pos at %d-%d", p.row, p.col);
	}
}

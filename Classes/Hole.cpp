#include "Hole.h"
#include "Obj.h"
#include "Skill.h"

Hole::Hole(Node* parrent):
	_node(nullptr),
	_represent(nullptr),
	_skill(nullptr),
	_position(pos(0,0))
{
	if(parrent)
		init(parrent);
}

Hole::~Hole()
{
	release();
}

void Hole::init(Node* parrent)
{
	release();

	_node = Node::create();
	parrent->addChild(_node);
}

void Hole::collect(shared_ptr<Obj> obj)
{
    obj->sprite->retain();
    obj->sprite->removeFromParentAndCleanup(true);
    _node->addChild(obj->sprite);
    obj->sprite->autorelease();
    
    Vec2 posInNode = _node->convertToNodeSpace(Board::gridPos->realPos(obj->getPosition()));
    obj->sprite->setPosition(posInNode);
}

void Hole::setPosition(const pos& pos)
{
    _position = pos;
    Vec2 realpos = Board::gridPos->realPos(_position);
    
    _node->setPosition(realpos);
    if(_represent)
        _represent->setPosition(realpos);
}

void Hole::update(float dt)
{

}

void Hole::release()
{
	CC_SAFE_DELETE(_node);
	CC_SAFE_DELETE(_represent);
	_skill = nullptr;
}

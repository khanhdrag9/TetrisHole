#include "Hole.h"
#include "Obj.h"
#include "Skill.h"
#include "Templates.h"

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

void Hole::initSkill(bool reset, const int& speed)
{
	if (reset)
		_skill = make_unique<Skill>();
	
	if (_skill)
		_skill->setSpeed(speed);
	else
		CCLOG("Cannot set speed when skill is null!");
}

void Hole::setRepresent(Sprite* sprite)
{
	if (_node)
	{
		_represent = sprite;
		_node->addChild(_represent);
		_represent->setPosition(0, 0);
	}
	else
	{
		CCLOG("Hole Node is null so can not set represent for the node");
	}
}

void Hole::collect(shared_ptr<Obj> obj)
{
    obj->sprite->retain();
    obj->sprite->removeFromParentAndCleanup(true);
    _node->addChild(obj->sprite);
    obj->sprite->autorelease();
    
    Vec2 posInNode = _node->convertToNodeSpace(Board::gridPos->realPos(obj->getPosition()));
    obj->sprite->setPosition(posInNode);

	_objsUnContainer.push_back(obj);
}

void Hole::setPosition(const pos& p)
{
	pos incre = p - _position;
    _position = p;
    Vec2 realpos = Board::gridPos->realPos(_position);
    
    _node->setPosition(realpos);

	//set oldpos = null to reset board 
	for (auto& obj : _objsUnContainer)
	{
		Board::girdObj->getObj(obj->getPosition()) = nullptr;
	}

	for (auto& o : _objsUnContainer)
	{
		if (o)
		{
			pos newpos = o->getPosition() + incre;
			o->setPosition(newpos, false);
		}
	}
}

void Hole::update(float dt)
{
    if(_skill)
        _skill->update(*this ,dt);
}

void Hole::release()
{
	CC_SAFE_DELETE(_node);
	CC_SAFE_DELETE(_represent);
	_skill = nullptr;
}

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
	_node->addChild(obj->sprite);
}

void Hole::setPosition(const pos& pos)
{

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
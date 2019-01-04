#include "Hole.h"
#include "Skill.h"
#include "Board.h"

Hole::Hole():
	_spriteNode(nullptr),
	_boardParrent(nullptr),
	_skill(nullptr)
{
	_spriteNode = Node::create();
}

Hole::~Hole()
{

}

void Hole::useSkill()
{
	if (_skill && _boardParrent)
	{
		_skill->use(_boardParrent);
	}
}

void Hole::setSkill(const skill skill)
{
	if (skill == skill::stuck)
	{
		_skill = make_unique<Suck>(_spriteNode->getPosition());
	}

}
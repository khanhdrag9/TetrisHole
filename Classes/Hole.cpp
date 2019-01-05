#include "Hole.h"
#include "Skill.h"
#include "Board.h"
#include "Templates.h"

Hole::Hole():
	_spriteNode(nullptr),
	_boardParrent(nullptr),
	_skill(nullptr)
{
	_spriteNode = Node::create();
}

Hole::~Hole()
{
    CC_SAFE_DELETE(_spriteNode);
    _boardParrent = nullptr;
    _skill = nullptr;
}

void Hole::useSkill()
{
	if (_skill && _boardParrent)
	{
		_skill->use();
	}
}

void Hole::setSkill(const skill skill)
{
	if (skill == skill::stuck)
	{
		_skill = make_unique<Suck>(shared_from_this());
	}

}
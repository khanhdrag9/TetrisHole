#pragma once
#include "Header.h"

class gObject;
class Board;
class Skill;

class Hole : public enable_shared_from_this<Hole>
{
	friend class Board;


	Node* _spriteNode;

	shared_ptr<Board> _boardParrent;
	unique_ptr<Skill> _skill;
public:

	Hole();
	virtual ~Hole();

	void useSkill();
	void setSkill(const skill skill);

	Vec2 getPosition() const { return _spriteNode->getPosition(); }

};

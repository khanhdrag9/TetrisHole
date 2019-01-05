#pragma once
#include "Header.h"

class gObject;
class Board;
class Skill;

class Hole : public enable_shared_from_this<Hole>
{
	friend class Board;
    friend class Suck;


	Node* _spriteNode;

	shared_ptr<Board> _boardParrent;
	unique_ptr<Skill> _skill;
public:

	Hole();
	virtual ~Hole();

	void useSkill();
	void setSkill(const skill skill);

};

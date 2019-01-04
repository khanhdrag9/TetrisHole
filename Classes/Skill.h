#pragma once
#include "Header.h"

class Board;

class Skill
{
public:
	virtual void use(shared_ptr<Board>& board) = 0;
};

class Suck : public Skill
{
	Vec2 _posSuck;
public:
	Suck();
	Suck(const Vec2& pos);
	void use(shared_ptr<Board>& board) override;
};
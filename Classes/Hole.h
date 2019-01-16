#pragma once
#include "Header.h"

class Skill;
class Obj;

class Hole
{
	Node* _node;
	Sprite* _represent;
	unique_ptr<Skill> _skill;
	pos _position;

public:
	Hole(Node* parrent = nullptr);
	~Hole();

	void init(Node* parrent);
	void collect(shared_ptr<Obj> obj);
	void setPosition(const pos& pos);
	const pos& getPosition() const { return _position; }
	void update(float dt);
	void release();
};
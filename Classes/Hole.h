#pragma once
#include "Header.h"

class Skill;
class Obj;

class Hole : public enable_shared_from_this<Hole>
{
	Node* _node;
	Sprite* _represent;
	unique_ptr<Skill> _skill;
	pos _position;

	vector<shared_ptr<Obj>> _objsUnContainer;
public:
	Hole(Node* parrent = nullptr);
	~Hole();

	void init(Node* parrent);
	void setRepresent(Sprite* sprite);
	void collect(shared_ptr<Obj> obj);
	void setPosition(const pos& pos);
	const pos& getPosition() const { return _position; }
	const vector<shared_ptr<Obj>>& getObjs() const { return _objsUnContainer; }
	void update(float dt);
	void release();
};

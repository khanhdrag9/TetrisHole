#pragma once
#include "Header.h"

class GridPos;
class gObject;
class Hole;

class Board : public enable_shared_from_this<Board>
{
	//unique_ptr<GridPos> _gridPos;
	vector<shared_ptr<gObject>> _listObject;
	shared_ptr<Hole> _hole;

public:
	Board();
	Board(const int& row, const int& col);
	void init(const int& row, const int& col);
	void initGrid(const int& row, const int& col);
	void collectObject(const shared_ptr<gObject>& object);
	void setHole(const shared_ptr<Hole>& hole);
	void setHoleSkill(const skill typeSkill);

	void update(float dt);


	friend class Suck;
};
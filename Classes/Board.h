#pragma once
#include "Grid.h"

class GridPos;
class gObject;
class Hole;

class Board : public enable_shared_from_this<Board>
{
	GridPos _gridPos;
	vector<shared_ptr<gObject>> _listObject;
    Node* _parrentObject;
	shared_ptr<Hole> _hole;
    shared_ptr<gObject> _representHole;

    float _sideBox;
    float _maxW;
    float _maxH;
public:
	Board();
	Board(const int& row, const int& col);
    ~Board();
    
	void init(const int& row, const int& col);
	void initGrid(const int& row, const int& col);
	void collectObject(const shared_ptr<gObject>& object);
    
	void setHole(const shared_ptr<Hole>& hole);
	void setHoleSkill(const skill typeSkill, std::function<void()> callback = nullptr);
    void setRepresentHole(const shared_ptr<gObject>& obj);
    void setNode(Node* node);
    
    int getSideBox() const {return _sideBox; }
    shared_ptr<gObject> getRepresentHole(){return _representHole;}
    vector<shared_ptr<gObject>> getListObjects(){return _listObject;}
    GridPos getGridPos() const { return _gridPos; }

	void update(float dt);


	friend class Suck;
};

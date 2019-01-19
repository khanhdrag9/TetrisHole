#pragma once
#include "Header.h"
#include "Templates.h"

class CreateManager;
class ContainerManager;
class Board;
class Container;
class Hole;
class Obj;

enum collision_pos : int //Has is represent for the number of type collision
{
    TOP = 0,
    BOT,
    LEFT,
    RIGHT,
    TOP_LEFT,
    TOP_RIGHT,
    BOT_LEFT,
    BOT_RIGHT,
    AXIS,
    HAS
};

enum class direction
{
    NONE,
    LEFT,
    RIGHT
};

using check_collision = array<bool, (int)collision_pos::HAS>;
using scan_direct_obj = map<collision_pos, list<pos>>;

class GameManager : public Singleton<GameManager>
{
    unique_ptr<CreateManager> _createMg;
    unique_ptr<ContainerManager> _containerMg;
    unique_ptr<Board> _board;
	unique_ptr<Hole> _hole;
    
    //vector<shared_ptr<Container>> _containers;
	//vector<shared_ptr<Obj>> _objsUnContainer;

	bool _createdContainer;
    
    Vec2 _touchBegin;
    Vec2 _rangerTouch;

	float _count_time;
	float _interval_time;
    direction _holeDirect;
    
    Node* _current;
    Size _screenSize;
    Vec2 _origin;
    
public:
    GameManager();
    ~GameManager();
    void setNodeParrent(Node* node);
    
	void update(float dt);
    void scan();
    void scanScore(const shared_ptr<Obj>& objstart, collision_pos direct, scan_direct_obj& beforeObjs);
    void deleteScoreObj(const pos& axisObjPos, scan_direct_obj& beforeObjs);
    
    bool touchBegan(Touch* touch, Event* event);
    void touchMoved(Touch* touch, Event* event);
    void touchEnded(Touch* touch, Event* event);
    
    check_collision getCollisionPos(const pos& p) const;
    check_collision getCollisionPos(const shared_ptr<Container>& container) const;
    check_collision getCollisionPos(const unique_ptr<Hole>& hole) const;
    
	pos _createTop;
	pos _createBot;
	pos _axis;
    
    static scan_direct_obj defaultScanDirectObj();
private:
    
    void addChild(shared_ptr<Container> container);
	void createContainer();
	void moveByContainer(shared_ptr<Container> container, const pos& incre);
    void moveByHole(const pos& incre);
    bool checkPos(const pos& p);
    
};

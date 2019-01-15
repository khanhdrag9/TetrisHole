#pragma once
#include "Header.h"
#include "Templates.h"

class CreateManager;
class ContainerManager;
class Board;
class Container;

enum collision_pos  //Has is represent for the number of type collision
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

using check_collision = array<bool, (int)collision_pos::HAS>;

class GameManager : public Singleton<GameManager>
{
    unique_ptr<CreateManager> _createMg;
    unique_ptr<ContainerManager> _containerMg;
    unique_ptr<Board> _board;
    
    //vector<shared_ptr<Container>> _containers;

	bool _createdContainer;

	float _count_time;
	float _interval_time;
    
    Node* _current;
    Size _screenSize;
    Vec2 _origin;
    
public:
    GameManager();
    ~GameManager();
    void setNodeParrent(Node* node);
    
	void update(float dt);
    
	pos _createTop;
	pos _createBot;
	pos _axis;
    
    
private:
    
    void addChild(shared_ptr<Container> container);
	void createContainer();
	void moveByContainer(shared_ptr<Container> container, const pos& incre);
    bool checkPos(const pos& p);
    check_collision getCollisionPos(const pos& p) const;
	check_collision getCollisionPos(const shared_ptr<Container>& container) const;

};

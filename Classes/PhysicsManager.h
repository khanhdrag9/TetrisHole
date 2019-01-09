#pragma once
#include "Header.h"

class gObject;
class Board;

enum class CollisionType
{
	NONE,
	HAS,
	DOWN,
	LEFT,
	RIGHT
};

class PhysicsManager
{
public:
    PhysicsManager();
    ~PhysicsManager();
    void setting();
	CollisionType checkCollision(const shared_ptr<gObject>& obj, const shared_ptr<Board>& board);
};

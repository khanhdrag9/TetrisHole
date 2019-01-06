#pragma once
#include "Header.h"

class gObject;
class Board;

class PhysicsManager
{
    PhysicsWorld* _physWorld;
public:
    PhysicsManager(PhysicsWorld* world);
    ~PhysicsManager();
    void setting();
    void addPhysicsForObject(const shared_ptr<gObject>& obj, bool dynamic, shape type = shape::CIRCLE);
    bool onContactBegin(PhysicsContact& contact, shared_ptr<Board>& board);
};

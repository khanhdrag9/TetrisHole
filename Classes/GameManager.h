#pragma once
#include "Header.h"
#include "Templates.h"

class CreateManager;
class ContainerManager;
class Board;
class Container;

class GameManager : public Singleton<GameManager>
{
    unique_ptr<CreateManager> _createMg;
    unique_ptr<ContainerManager> _containerMg;
    unique_ptr<Board> _board;
    
    vector<shared_ptr<Container>> _containers;
    
    Node* _current;
    Size _screenSize;
    Vec2 _origin;
    
public:
    GameManager();
    ~GameManager();
    void setNodeParrent(Node* node);
    
    void createContainer();
    
	pos _createTop;
	pos _createBot;
private:
    void addChild(shared_ptr<Container> container);
};

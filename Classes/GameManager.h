#pragma once
#include "Header.h"
#include "Templates.h"

class CreateManager;
class Container;

class GameManager : public Singleton<GameManager>
{
    unique_ptr<CreateManager> _createMg;
    
    
    vector<shared_ptr<Container>> _containers;
    
    Node* _parrent;
public:
    GameManager();
    ~GameManager();
    void setNodeParrent(Node* node);
    
    void createContainer();
    
    
private:
    void addChild(shared_ptr<Container> container);
};

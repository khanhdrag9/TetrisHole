#pragma once
#include "Header.h"

class Board;
class Hole;
class GObjectManager;
class PhysicsManager;
class gObject;

class GamePlay : public Layer
{
public:
    static Scene* createScene();
    
    bool init() override;
    
    CREATE_FUNC(GamePlay);

    GamePlay();
    virtual ~GamePlay();


	static pos createUp;
	static pos createDown;
private:
	shared_ptr<Board> _board;
    unique_ptr<GObjectManager> _objMgr;
    unique_ptr<PhysicsManager> _phyMgr;
    
    bool _isCreated;
    
    Size _screenSize;
    Vec2 _origin;
    
	
private:
	void initBoard();
    void initObjectStart();
    void initListeners();
	void initSchedule();

    void createCircle(bool up);
	void deleteCircle(list<gObject> listObj);
    
    void update(float dt)  override;
};

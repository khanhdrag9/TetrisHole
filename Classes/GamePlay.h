#include "Header.h"

class Board;
class Hole;
class GObjectManager;

class GamePlay : public Layer
{
public:
    static Scene* createScene();
    
    bool init() override;
    
    CREATE_FUNC(GamePlay);

    GamePlay();
    virtual ~GamePlay();
private:
	shared_ptr<Board> _board;
    unique_ptr<GObjectManager> _objMgr;
    
    Size _screenSize;
    Vec2 _origin;

private:
	void initBoard();
    void initObjectStart();
	void initSchedule();


    void update(float dt)  override;
};

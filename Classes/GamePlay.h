#include "Header.h"

class Board;
class Hole;

class GamePlay : public Layer
{
public:
    static Scene* createScene();
    
    bool init() override;
    
    CREATE_FUNC(GamePlay);

private:
	shared_ptr<Board> _board;


private:
	void initBoard();
	void initSchedule();


	void update(float dt);
};

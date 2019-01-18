#include "Skill.h"
#include "Hole.h"
#include "GameManager.h"
#include "Obj.h"

Skill::Skill():
    _speed(0)
{

}

Skill::~Skill()
{

}

void Skill::setSpeed(const int& speed)
{
	_speed = speed;
}

void Skill::update(Hole& hole, float dt)
{
    pos axis = hole.getPosition();
    
	list<pos> move;

    for(auto& obj : hole.getObjs())
    {
        pos objpos = obj->getPosition();
        
        auto listCol = GameManager::getInstance()->getCollisionPos(objpos);
        
		//set oldpos = null to reset board 
		/*for (auto& obj : hole.getObjs())
		{
			Board::girdObj->getObj(obj->getPosition()) = nullptr;
		}*/

		pos newpos = objpos;
        if(objpos.row > axis.row && !listCol[collision_pos::BOT])
        {
			newpos.row -= _speed;
        }
        else if(objpos.row < axis.row && !listCol[collision_pos::TOP])
        {
			newpos.row += _speed;
        }
        
        if(objpos.col > axis.col && !listCol[collision_pos::LEFT])
        {
			newpos.col -= _speed;
        }
        else if(objpos.col < axis.col && !listCol[collision_pos::RIGHT])
        {
			newpos.col += _speed;
        }
		move.push_back(newpos);
		//obj->setPosition(newpos, true);
    }

	//set oldpos = null to reset board 
	for (auto& obj : hole.getObjs())
	{
		Board::girdObj->getObj(obj->getPosition()) = nullptr;
	}

	for (auto& obj : hole.getObjs())
	{
		obj->setPosition(move.front(), true);
		move.pop_front();
	}
}

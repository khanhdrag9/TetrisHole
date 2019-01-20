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
        
    }

	//set oldpos = null to reset board 
	for (auto& obj : hole.getObjs())
	{
		
	}

	for (auto& obj : hole.getObjs())
    //for(int i = 0; i < hole.getObjs().size(); i++)
	{
//        if(obj->getPosition() != move.front())
//        {
//            scan_direct_obj sdo = GameManager::defaultScanDirectObj();
//            GameManager::getInstance()->scanScore(obj, collision_pos::AXIS, sdo);
//            GameManager::getInstance()->deleteScoreObj(obj->getPosition(), sdo);
//        }
        
        if(obj)
        {
            
        }
		
		move.pop_front();
	}
    
}

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

void Skill::update(Hole& hole, float dt)
{
    pos axis = hole.getPosition();
    
    for(auto& obj : hole.getObjs())
    {
        pos objpos = obj->getPosition();
        pos axis = GameManager::getInstance()->_axis;
        
        auto listCol = GameManager::getInstance()->getCollisionPos(objpos);
        
        if(objpos.row > axis.row && !listCol[collision_pos::LEFT])
        {
            //obj->setPosition(<#const pos &p#>, bool useRealPos)
        }
        else if(objpos.row < axis.row)
        {
            
        }
        
        if(objpos.col > axis.col)
        {
            
        }
        else if(objpos.col < axis.col)
        {
            
        }
        
    }
}

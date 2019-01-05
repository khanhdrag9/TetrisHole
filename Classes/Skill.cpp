#include "Skill.h"
#include "Board.h"
#include "Hole.h"
#include "Object.h"

Skill::Skill(const shared_ptr<Hole> hole):
    _hole(hole)
{
}

Skill::~Skill()
{
    _hole = nullptr;
}

void Skill::use()
{
}

//Suck
void Suck::use()
{
    int numObj = (int)_hole->_boardParrent->_listObject.size();
    auto listObject = _hole->_boardParrent->_listObject;
	for (int i = 0; i < numObj; i++)
	{
        Vec2 holePos = _hole->_boardParrent->_representHole->getSprite()->getPosition();
        if(listObject[i] && listObject[i]->getSprite()->getNumberOfRunningActions() == 0)
        {
            listObject[i]->getSprite()->runAction(MoveTo::create(3.f, holePos));
        }
	}
}

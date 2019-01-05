#include "Skill.h"
#include "Board.h"
#include "Hole.h"

Skill::Skill(const shared_ptr<Hole>& hole):
    _hole(hole)
{
}

void Skill::use()
{
}

//Suck
void Suck::use()
{
    int numObj = (int)_hole->_boardParrent->_listObject.size();
	for (int i = 0; i < numObj; i++)
	{
        
	}
}

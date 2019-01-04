#include "Skill.h"
#include "Board.h"

Suck::Suck()
{
}

Suck::Suck(const Vec2& pos)
{
	_posSuck = Vec2(pos);
}

void Suck::use(shared_ptr<Board>& board)
{
	for (int i = 0; i < board->_listObject.size(); i++)
	{

	}
}
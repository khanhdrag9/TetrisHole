#include "Container.h"
#include "Obj.h"
#include "Board.h"
#include "Support.h"

Container::Container(const int& number)
{
    init(number);
}

Container::~Container()
{
    release();
}

std::pair<Obj::Color, string> getColor()
{
    int random = support::getRandom((int)Obj::Color::BLUE, (int)Obj::Color::YELLOW);
 
    std::pair<Obj::Color, string> result;
    result.first = (Obj::Color)random;
    
    switch (result.first)
    {
        case Obj::Color::BLUE:
            result.second = "Blue.png";
            break;
        case Obj::Color::RED:
            result.second = "Red.png";
            break;
        case Obj::Color::YELLOW:
            result.second = "Yellow.png";
            break;
        default:
            CCLOG("Fail get random Color");
            break;
    }
    
    return result;
}

void Container::init(const int &number)
{
    release();
    //create objs in container
    list<pos> listp = {
        pos(0,0),
        pos(0,1),
        pos(0,2)
    };
    
    for(int i = 0; i < number; ++i)
    {
        auto mesh = getColor();
        _objs.emplace_back(make_shared<Obj>(mesh.second.c_str(), mesh.first));
        float scale = Board::sideObj / (float)_objs[i]->sprite->getContentSize().width ;
        _objs[i]->sprite->setScale(scale);
        _objs[i]->setPosition(*listp.begin(), true);
        
        listp.pop_front();
    }
}

void Container::setPosition(const pos& p)
{
    int axis = (int)_objs.size() / 2;
    pos curpos = _objs[axis]->getPosition();
    pos posincre = pos(p.row - curpos.row, p.col - curpos.col);
    
	//set oldpos = null to reset board 
	for (auto& obj : _objs)
	{
		Board::girdObj->getObj(obj->getPosition()) = nullptr;
	}

    for(int i = 0; i < _objs.size(); i++)
    {
        pos op = _objs[i]->getPosition();
        pos newp = op + posincre;
        _objs[i]->setPosition(newp, true);
        
    }
}

pos Container::getPosition() const
{
	int axis = (int)_objs.size() / 2;
	if (_objs.size() > axis)
	{
		return _objs[axis]->getPosition();
	}
	
	return pos(-1, -1);
}

void Container::release()
{
    for(auto& o : _objs)
        o = nullptr;
    _objs.clear();
}




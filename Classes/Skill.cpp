#include "Skill.h"
#include "Board.h"
#include "Hole.h"
#include "Object.h"

Skill::Skill(const shared_ptr<Hole> hole, std::function<void()> callback):
    _hole(hole),
    _callback(callback),
    _counttime(0.f),
    _interval(0.f)
{
}

Skill::~Skill()
{
    _hole = nullptr;
}

void Skill::use(float dt)
{
}

void Skill::active(void* value)
{
}

//Suck
void Suck::active(void* value)
{
    auto v = static_cast<int*>(value);
    _speed = *v;
    
    CC_SAFE_DELETE(v);
}

void Suck::use(float dt)
{
    if(_counttime >= _interval)
    {
        int numObj = (int)_hole->_boardParrent->_listObject.size();
        auto board = _hole->_boardParrent;
        auto listObject = board->_listObject;
        for (int i = 0; i < numObj; i++)
        {
            auto obj = listObject[i];
            if(_hole->_boardParrent->_representHole && listObject[i])
            {
                pos hole = board->_representHole->getPosition();
                pos objpos = obj->getPosition();
                
                //for verical
                if(hole.row < objpos.row)
                {
                    drop(obj, true);
                }
                else if(hole.row > objpos.row)
                {
                    drop(obj, false);
                }
                
                //for hozi
                if(hole.col < objpos.col)
                {
                    drop(obj, true);
                }
                else if(hole.col > objpos.col)
                {
                    drop(obj, false);
                }
            }
            
        }
        _counttime = 0.f;
    }
    
    _counttime += dt;
}

void Suck::drop(shared_ptr<gObject> obj, bool upto)
{
    pos newpos = obj->getPosition();
    if(upto)    //drop down
    {
        newpos.row-=_speed;
    }
    else    //drop up
    {
        newpos.row+=_speed;
    }
    
    obj->setPosition(newpos, _hole->_boardParrent);
}

void Suck::slide(shared_ptr<gObject> obj, bool left)
{
    pos newpos = obj->getPosition();
    if(left)    //drop down
    {
        newpos.col-=_speed;
    }
    else    //drop up
    {
        newpos.col+=_speed;
    }
    
    obj->setPosition(newpos, _hole->_boardParrent);
}

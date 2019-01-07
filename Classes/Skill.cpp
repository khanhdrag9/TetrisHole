#include "Skill.h"
#include "Board.h"
#include "Hole.h"
#include "Object.h"

Skill::Skill(const shared_ptr<Hole> hole, std::function<void()> callback):
    _hole(hole),
    _callback(callback)
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
    auto v = static_cast<float*>(value);
    _speed = *v;
    
    CC_SAFE_DELETE(v);
}

void Suck::use(float dt)
{
    int numObj = (int)_hole->_boardParrent->_listObject.size();
    auto listObject = _hole->_boardParrent->_listObject;
	for (int i = 0; i < numObj; i++)
	{
        auto obj = listObject[i];
        if(_hole->_boardParrent->_representHole && listObject[i])
        {
            if(listObject[i]->getStatus() == gObject::status::MOVING)
            {
                /*thread action([this](shared_ptr<gObject> obj, float dt){

                    mtx.lock();*/
                    auto speed = _speed;
                    auto me = obj->getSprite()->getPosition();
					CCLOG("Obj[%d] Pos: %f-%f", i, me.x, me.y);

                    auto target = _hole->_boardParrent->_representHole->getSprite()->getPosition();
                    auto diff = target - obj->getSprite()->getPosition();
                    auto change = diff.getNormalized() * speed * dt;
                    if(diff.length() > change.length())
                    {
                        obj->getSprite()->setPosition(me + change);
                    }
                    else
                    {
                        obj->getSprite()->setPosition(target);
                        if(_callback)
                        {
                            _callback();
                        }
                    }
                    
                /*    mtx.unlock();
                }, listObject[i], dt);
                
                if(action.joinable())
                    action.join();*/
                //action.detach();
                
            }
            else if(listObject[i]->getStatus() == gObject::status::NONE)
            {
                
                
            }
            else if(listObject[i]->getStatus() == gObject::status::COLLISION)
            {
                
            }
        }
        
	}
}

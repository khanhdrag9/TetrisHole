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
        if(_hole->_boardParrent->_representHole && listObject[i])
        {
//            Vec2 holePos = _hole->_boardParrent->_representHole->getSprite()->getPosition();
//            if(listObject[i] && listObject[i]->getSprite()->getNumberOfRunningActions() == 0)
//            {
//                listObject[i]->getSprite()->runAction(MoveTo::create(3.f, holePos));
//                listObject[i]->getSprite()->runAction(Follow::create(_hole->_boardParrent->getRepresentHole()->getSprite()));
//            }
            thread action([this](shared_ptr<gObject> obj, float dt){
                
                mtx.lock();
                auto speed = _speed;
                auto me = obj->getSprite()->getPosition();
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
                }
                
                mtx.unlock();
            }, listObject[i], dt);
            
            if(action.joinable())
                action.join();
            //action.detach();
        }
	}
}

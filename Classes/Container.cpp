#include "Container.h"
#include "Obj.h"
#include "Grid.h"
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
//    release();
    //create objs in container
    list<pos> listp = {
        pos(0,-1),
        pos(0,0),
        pos(0,1)
    };
    Vec2 startp = Vec2(Board::sideObj, Board::sideObj) * 0.5f;
    
    _node = Node::create();
    
    for(int i = 0; i < number; ++i)
    {
        auto mesh = getColor();
        _objs.emplace_back(make_shared<Obj>(mesh.second.c_str(), mesh.first));
        float scale = Board::sideObj / (float)_objs[i]->sprite->getContentSize().width ;
        _objs[i]->sprite->setScale(scale);
        pos curpos = listp.front();
        Vec2 realpos = startp + Vec2(Board::sideObj * curpos.col, Board::sideObj * curpos.row);
        _objs[i]->setPosition(realpos);
        
        _node->addChild(_objs[i]->sprite);
        listp.pop_front();
    }
}

void Container::setPosition(const pos& p)
{
    _node->setPosition(Board::gridPos->realPos(p));
}

const Vec2& Container::getPosition() const
{
    return _node->getPosition();
}

void Container::release()
{
    for(auto& o : _objs)
        o = nullptr;
    _objs.clear();
    
    _node->removeFromParentAndCleanup(true);
    CC_SAFE_DELETE(_node);
}




#include "Container.h"
#include "Obj.h"

Container::Container(const int& number)
{
    init(number);
}

Container::~Container()
{
    release();
}

void Container::init(const int &number)
{
    release();
    //create objs in container
    for(int i = 0; i < number; ++i)
    {
        _objs.emplace_back(make_shared<Obj>("Circle.png"));
    }
}

void Container::release()
{
    for(auto& o : _objs)
        o = nullptr;
    _objs.clear();
}




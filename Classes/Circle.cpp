//
//  Square.cpp
//  TetrisHole-mobile
//
//  Created by Khanh on 1/2/19.
//

#include "Circle.h"
#include "Object.h"

//Container
Container::Container()
{
}

Container::~Container()
{
    _object = nullptr;
}

Container::Container(const shared_ptr<gObject>& obj):
_object(obj)
{
}

//Circle
Circle::Circle()
{
}

Circle::~Circle()
{
}

Circle::Circle(const shared_ptr<gObject>& obj) : Container(obj)
{
}

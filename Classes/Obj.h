#pragma once
#include "Header.h"

class Board;

class Obj : public enable_shared_from_this<Obj>
{
public:
    enum class Color : int
    {
        BLUE,
        RED,
        YELLOW
    };
    
protected:
    Color _color;
    
public:
    Obj(const char* path, Color color);
    virtual ~Obj();
    
    Sprite* sprite;
    
    void setPosition(const Vec2& p);
    
    inline const Vec2& getPosition() const
    {
        return sprite->getPosition();
    }
    inline const Color& getColor() const
    {
        return _color;
    }
};

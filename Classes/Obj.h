#pragma once
#include "Header.h"

class Board;

class Obj
{
    pos _position;
public:
    Obj(const char* path);
    virtual ~Obj();
    
    Sprite* sprite;
    
    inline void setPosition(const pos& p);
    inline const pos& getPosition() const;
};

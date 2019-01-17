#pragma once

//system
#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <vector>
#include <array>

using namespace std;

//Cocos
#include "cocos2d.h"

USING_NS_CC;


//Game


#define COL 20
#define ROW 40
#define ENABLE_DEBUG_GRID 1
#define FONT_ARIAL "fonts/arial.ttf"
#define HOLE_REPRE "HoleTest.png"

struct pos
{
	int row, col;

	pos() {}
	pos(const int& irow, const int& icol) : row(irow), col(icol) {}

	void operator=(const pos& ipos)
	{
		row = ipos.row;
		col = ipos.col;
	}
	pos operator+(const pos& ipos)
	{
		return pos(row + ipos.row, col + ipos.col);
	}
	pos operator-(const pos& ipos)
	{
		return pos(row - ipos.row, col - ipos.col);
	}
    bool operator==(const pos& ipos)
    {
        return (row == ipos.row && col == ipos.col);
    }
    
    bool operator!=(const pos& ipos)
    {
        return (row != ipos.row || col != ipos.col);
    }
    
    bool operator<(const pos& ipos)
    {
        if(row < ipos.row)
            return true;
        else if(row == ipos.row)
        {
            if(col < ipos.col)return true;
            else return false;
        }
        else
            return false;
    }
    
    bool operator>(const pos& ipos)
    {
        if(*this != ipos && !(*this < ipos))return true;
        else return false;
    }
};

static pos operator+(const pos& ipos1, const pos& ipos2)
{
    return pos(ipos1.row + ipos2.row, ipos1.col + ipos2.col);
}

static pos operator-(const pos& ipos1, const pos& ipos2)
{
	return pos(ipos1.row - ipos2.row, ipos1.col - ipos2.col);
}

static bool operator!=(const pos& ipos1, const pos& ipos2)
{
    return (ipos1.row != ipos2.row || ipos1.col != ipos2.col);
}

static bool operator==(const pos& ipos1, const pos& ipos2)
{
    return (ipos1.row == ipos2.row && ipos1.col == ipos2.col);
}

static bool operator<(const pos& ipos1, const pos& ipos2)
{
    if(ipos1.row < ipos2.row)
        return true;
    else if(ipos1.row == ipos2.row)
    {
        if(ipos1.col < ipos2.col)return true;
        else return false;
    }
    else
        return false;
}

static bool operator>(const pos& ipos1, const pos& ipos2)
{
    if(ipos1 != ipos2 && !(ipos1 < ipos2))return true;
    else return false;
}

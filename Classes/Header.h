#pragma once

//system
#include <iostream>
#include <memory>
#include <map>

using namespace std;

//Cocos
#include "cocos2d.h"

USING_NS_CC;


//Game
#include "h_Entity.h"


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
		return pos(row + ipos.row, col + ipos.col);
	}

	bool operator==(const pos& ipos)
	{
		return (row == ipos.row && col == ipos.col);
	}
};
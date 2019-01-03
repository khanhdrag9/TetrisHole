#pragma once
#include "Templates.h"
#include "Header.h"

class GridPos : public gridBase<Vec2>
{
public:
	GridPos();
	GridPos(const int& row, const int& col);
	void init(const int& row, const int& col);
};
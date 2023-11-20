#pragma once
#include "grid_data.h"

class grid
{
public:
	grid_data _grid_data;
	grid();
	void grid_put(grid_data color);
	void turnover();
};
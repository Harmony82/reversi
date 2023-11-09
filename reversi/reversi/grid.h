#pragma once
enum class grid_data
{
	NONE,
	BLACK,
	WHITE,
};
class grid
{
public:
	grid_data _grid_data;
	grid();
	void put_black();
	void put_white();
	void turnover();
};


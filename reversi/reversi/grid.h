#pragma once
enum class grid_data
{
	NONE,
	BLACK,
	WHITE,
};
class grid
{
private:
	grid_data _grid_data;
public:
	grid();
	void put_black();
	void put_white();
	void turnover();
};


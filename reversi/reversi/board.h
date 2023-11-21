#pragma once
#include"grid.h"
#include <vector>
#include "vector2int.h"
#include "grid_data.h"

class board
{
private:
	int length;
public:
	std::vector<std::vector<grid>> _board;
public:
	void show_board();
	void board_Initialize(int length);
	bool put_disc(vector2int point, grid_data color);
	bool can_put(vector2int point, grid_data color);
	int get_length();
private:
	void put_influence(vector2int point);
	bool Is_inboard(int column, int line);
};
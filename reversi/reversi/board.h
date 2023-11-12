#pragma once
#include"grid.h"
#include <vector>
#include "vector2int.h"
#include "grid_data.h"

class board
{
private:
	std::vector<std::vector<grid>> _board;
	int length;
public:
	board();
	void show_board();
	void board_Initialize(int length);
	bool put_disc(vector2int point,grid_data color);
};
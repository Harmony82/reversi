#pragma once
#include"grid.h"
#include <vector>


class board
{
private:
	std::vector<std::vector<grid>> _board;
public:
	board(int length);
	void show_board();
};


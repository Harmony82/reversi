#pragma once
#include"grid.h"
#include <vector>


class board
{
	std::vector<std::vector<grid>> _board();
public:
	board(int length);
};


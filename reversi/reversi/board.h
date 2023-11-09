#pragma once
#include"grid.h"
#include <vector>


class board
{
private:
	std::vector<std::vector<grid>> _board;
	int length;
public:
	board();
	void show_board();
	void board_Initialize(int length);
};
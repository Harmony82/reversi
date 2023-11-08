#include <iostream>
#include "board.h"

board::board(int length)
{
	_board.resize(length, std::vector<grid>(length));
}
void board::show_board()
{
	for (int ii = 0; ii < _board.size(); ii++)
	{
		for (int i = 0; i < _board.size(); i++)
		{
			std::cout << "+--";
		}
		std::cout << "+";
		for (int i = 0; i < _board.size(); i++)
		{
			std::cout << "|";
			if (_board[ii][i]._grid_data == grid_data::NONE)
			{
				std::cout << "@";
			}
			if (_board[ii][i]._grid_data == grid_data::BLACK)
			{
				std::cout << "Z";
			}
			if (_board[ii][i]._grid_data == grid_data::WHITE)
			{
				std::cout << "œ";
			}
		}
		std::cout << "|";
	}
	for (int i = 0; i < _board.size(); i++)
	{
		std::cout << "+--";
	}
	std::cout << "+";
}
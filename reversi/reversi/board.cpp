#include <iostream>
#include "board.h"

board::board()
{

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
		std::cout << "\n";
		for (int i = 0; i < _board.size(); i++)
		{
			std::cout << "|";
			if (_board[ii][i]._grid_data == grid_data::NONE)
			{
				std::cout << "�@";
			}
			if (_board[ii][i]._grid_data == grid_data::BLACK)
			{
				std::cout << "�Z";
			}
			if (_board[ii][i]._grid_data == grid_data::WHITE)
			{
				std::cout << "��";
			}
		}
		std::cout << "|";
		std::cout << "\n";
	}
	for (int i = 0; i < _board.size(); i++)
	{
		std::cout << "+--";
	}
	std::cout << "+";
}
int Initial_placement_length(int whole_length)
{
	int tmp = (whole_length - 4) / 2;
	if (tmp % 2 == 1)
	{
		tmp--;
	}
	if (whole_length % 2 == 1)
	{
		tmp++;
	}
	return tmp;
}
void board::board_Initialize(int length)
{
	_board.resize(length, std::vector<grid>(length));
	this->length = length;

}
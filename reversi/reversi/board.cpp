#include <iostream>
#include "board.h"
#include "grid_data.h"

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
	_board[3][3]._grid_data = grid_data::BLACK;
	_board[3][4]._grid_data = grid_data::WHITE;
	_board[4][4]._grid_data = grid_data::BLACK;
	_board[4][3]._grid_data = grid_data::WHITE;
}
bool board::put_disc(vector2int point, grid_data color)
{
	if (point.column > length)return false;
	if (point.line > length)return false;
	if (_board[point.line][point.column]._grid_data != grid_data::NONE)return false;
	_board[point.line][point.column].grid_put(color);
	return true;
}
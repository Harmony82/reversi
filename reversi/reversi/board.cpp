#include <iostream>
#include "board.h"
#include "grid_data.h"
#include "vector2int.h"
#include <format>

void board::show_board()
{
	std::wcout << "   ";
	for (int i = 0; i < length; i++)
	{
		std::cout << std::format("{:2d}", i + 1) << " ";
	}
	std::cout << "\n";
	for (int ii = 0; ii < _board.size(); ii++)
	{
		std::cout << "  ";
		for (int i = 0; i < _board.size(); i++)
		{
			std::cout << "+--";
		}
		std::cout << "+";
		std::cout << "\n";
		std::cout << std::format("{:2d}", ii + 1);
		for (int i = 0; i < _board.size(); i++)
		{
			std::cout << "|";
			if (_board[ii][i]._grid_data == grid_data::NONE)
			{
				std::cout << "　";
			}
			if (_board[ii][i]._grid_data == grid_data::BLACK)
			{
				std::cout << "〇";
			}
			if (_board[ii][i]._grid_data == grid_data::WHITE)
			{
				std::cout << "●";
			}
		}
		std::cout << "|";
		std::cout << "\n";
	}
	std::cout << "  ";
	for (int i = 0; i < _board.size(); i++)
	{
		std::cout << "+--";
	}
	std::cout << "+";
	std::cout << "\n";
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
	if (!Is_inboard(point.column, point.line))return false;
	if (_board[point.line][point.column]._grid_data != grid_data::NONE)return false;
	if (!can_put(point, color))return false;
	_board[point.line][point.column].grid_put(color);
	put_influence(point);
	return true;
}
void board::put_influence(vector2int point)
{
	int dx[8] = { -1,0,1,1,1,0,-1,-1 };
	int	dy[8] = { -1,-1,-1,0,1,1,1,0 };
	for (int i = 0; i < 8; i++)
	{
		int search_point = 1;
		while (1)
		{
			if (!Is_inboard(point.column + (dx[i] * search_point), point.line + (dy[i] * search_point)))break;
			if (_board[point.line + (dy[i] * search_point)][point.column + (dx[i] * search_point)]._grid_data ==
				_board[point.line][point.column]._grid_data)
			{
				search_point--;
				for (search_point; search_point > 0; search_point--)
				{
					_board[point.line + (dy[i] * search_point)][point.column + (dx[i] * search_point)].turnover();
				}
				break;
			}
			if (_board[point.line + (dy[i] * search_point)][point.column + (dx[i] * search_point)]._grid_data == grid_data::NONE)
				break;
			search_point++;
		}
	}
}
bool board::Is_inboard(int column, int line)
{
	if (column < 0)return false;
	if (column >= length)return false;
	if (line < 0)return false;
	if (line >= length)return false;

	return true;
}
bool board::can_put(vector2int point, grid_data color)
{
	int dx[8] = { -1,0,1,1,1,0,-1,-1 };
	int	dy[8] = { -1,-1,-1,0,1,1,1,0 };
	if (_board[point.line][point.column]._grid_data != grid_data::NONE)return false;
	for (int i = 0; i < 8; i++)
	{
		int search_point = 1;
		while (1)
		{
			if (!Is_inboard(point.column + (dx[i] * search_point), point.line + (dy[i] * search_point)))break;
			if (_board[point.line + (dy[i] * search_point)][point.column + (dx[i] * search_point)]._grid_data == grid_data::NONE)break;
			if (_board[point.line + (dy[i] * search_point)][point.column + (dx[i] * search_point)]._grid_data == color)
			{
				if (search_point > 1)
					return true;
				else
					break;
			}
			search_point++;
		}
	}
	return false;
}
int board::get_length()
{
	return length;
}
void board::show_result()
{
	int black_count= count_disc(grid_data::BLACK);
	int white_count= count_disc(grid_data::WHITE);
	std::cout << "黒：" << black_count;
	std::cout << "\n";
	std::cout << "白：" << white_count;
	std::cout << "\n";

	if (black_count > white_count)
	{
		std::cout << "黒の勝ち！";
	}
	if (black_count < white_count)
	{
		std::cout << "白の勝ち！";
	}
	if (black_count == white_count)
	{
		std::cout << "引き分け！";
	}
}
int board::count_disc(grid_data color)
{
	int count=0;
	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++)
		{
			if (_board[i][ii]._grid_data == color)
			{
				count++;
			}
		}
	}
	return count;
}
bool board::can_put_somewhere(grid_data color)
{
	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++)
		{
			vector2int point(i, ii);
			if (can_put(point,color))
			{
				return true;
			}
		}
	}
	return false;
}
bool board:: detect_end(bool ispass[])
{
	if (ispass[0] == true && ispass[1] == true)
		return true;
	for (int i = 0; i < length; i++)
	{
		for (int ii = 0; ii < length; ii++)
		{
			if (_board[i][ii]._grid_data == grid_data::NONE)
				return false;
		}
	}
	return true;
}
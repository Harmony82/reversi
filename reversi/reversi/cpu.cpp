#include "cpu.h"
#include "vector2int.h"
#include <vector>
#include<iostream>
#include <random>
cpu::cpu()
{
	const grid_data usercolor = grid_data::WHITE;
	color = usercolor;
}
bool cpu::cpu_put(board& board)
{
	if (!board.can_put_somewhere(color))
	{
		std::cout << "�u����ꏊ���Ȃ��B�p�X�B";
		std::cout << "\n";
		return false;
	}
	board.put_disc(cpu_thinking(board), color);
	return true;
}
vector2int cpu::cpu_thinking(board board)
{
	std::random_device rand;
	std::vector<vector2int> candidate;
	for (int i = 0; i < board.get_length(); i++)
	{
		for (int ii = 0; ii < board.get_length(); ii++)
		{
			vector2int point(i, ii);
			if (board.can_put(point, color))
			{
				candidate.push_back(point);
			}
		}
	}
	return candidate[rand() % candidate.size()];
}
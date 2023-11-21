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
void cpu::cpu_put(board& board)
{
	board.put_disc(cpu_thinking(board), color);
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
#include "cpu.h"
#include<iostream>
cpu::cpu()
{
	const grid_data usercolor = grid_data::WHITE;
	color = usercolor;
}
void cpu::cpu_put(board& board)
{
	vector2int put_point;
	do
	{
		std::cout << "�΂�u���܂��B���W����͂��Ă��������B" << "\n";
		std::cout << "�c";
		std::cin >> put_point.column;
		std::cout << "��";
		std::cin >> put_point.line;
	} while (!board.put_disc(put_point, color));
}
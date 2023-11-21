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
		std::cout << "石を置きます。座標を入力してください。" << "\n";
		std::cout << "縦";
		std::cin >> put_point.column;
		std::cout << "横";
		std::cin >> put_point.line;
	} while (!board.put_disc(put_point, color));
}
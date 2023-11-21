#include "user.h"
#include "grid_data.h"
#include "vector2int.h"
#include <iostream>
user::user()
{
	const grid_data usercolor = grid_data::BLACK;
	color = usercolor;
}
bool user::user_put(board &board)
{
	vector2int put_point;
	while(1)
	{
		if (!board.can_put_somewhere(color))
		{
			std::cout << "�u����ꏊ������܂���B�p�X�B";
			std::cout << "\n";
			return false;
		}
		std::cout << "�΂�u���܂��B���W����͂��Ă��������B" << "\n";
		std::cout << "��";
		std::cin >> put_point.column;
		std::cout << "�c";
		std::cin >> put_point.line;
		put_point.column--;
		put_point.line--;
		if (board.put_disc(put_point, color))break;
		std::cout << "���͂��󂯕t���܂���ł����B�ēx���͂��Ă��������B";
	}
	return true;
}
#include "user.h"
#include "grid_data.h"
#include "vector2int.h"
#include <iostream>
user::user()
{
	const grid_data usercolor = grid_data::BLACK;
	color = usercolor;
}
void user::user_put(board &board)
{
	vector2int put_point;
	do
	{
		std::cout << "石を置きます。座標を入力してください。" << "\n";
		std::cout << "横";
		std::cin >> put_point.column;
		std::cout << "縦";
		std::cin >> put_point.line;
	} while (!board.put_disc(put_point,color));
}
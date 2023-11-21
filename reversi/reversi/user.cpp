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
			std::cout << "置ける場所がありません。パス。";
			std::cout << "\n";
			return false;
		}
		std::cout << "石を置きます。座標を入力してください。" << "\n";
		std::cout << "横";
		std::cin >> put_point.column;
		std::cout << "縦";
		std::cin >> put_point.line;
		put_point.column--;
		put_point.line--;
		if (board.put_disc(put_point, color))break;
		std::cout << "入力を受け付けませんでした。再度入力してください。";
	}
	return true;
}
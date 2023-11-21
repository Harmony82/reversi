#include <iostream>
#include "reversi.h"
#include "player.h"
#include "grid_data.h"
#include "user.h"
#include "cpu.h"
#include <chrono>
#include <thread>
reversi::reversi()
{

}
void reversi::game()
{
	const int length=8;
	bool ispass[2] = { false,false };
	user player1;
	cpu player2;

	game_board.board_Initialize(length);
	while (1)
	{
		game_board.show_board();
		ispass[0] = !player1.user_put(game_board);
		game_board.show_board();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		ispass[1] = !player2.cpu_put(game_board);
		if (game_board.detect_end(ispass))
		{
			game_board.show_board();
			game_board.show_result();
			std::cout << "ƒQ[ƒ€‚ðI—¹‚µ‚Ü‚·";
			break;
		}
	}
}
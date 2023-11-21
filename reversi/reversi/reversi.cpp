#include <iostream>
#include "reversi.h"
#include "player.h"
#include "grid_data.h"
#include "user.h"
#include "cpu.h"
reversi::reversi()
{

}
void reversi::game()
{
	int length;
	user player1;
	cpu player2;
	std::cin>>length;
	game_board.board_Initialize(length);
	while (1)
	{
		game_board.show_board();
		player1.user_put(game_board);
		player2.cpu_put(game_board);
	}
}
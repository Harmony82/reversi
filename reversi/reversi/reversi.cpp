#include <iostream>
#include "reversi.h"
reversi::reversi()
{

}
void reversi::game()
{
	int length;
	std::cin>>length;
	game_board.board_resize(length);
	game_board.show_board();
}
#include "player.h"
#include "board.h"
#include "vector2int.h"
#include "grid_data.h"

bool player::put(vector2int point,board game_board)
{
	return game_board.put_disc(point,color);
}
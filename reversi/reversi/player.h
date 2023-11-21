#pragma once
#include "vector2int.h"
#include "grid_data.h"
#include "board.h"

class player
{
protected:
	grid_data color;
	bool put(vector2int point,board game_board);
};
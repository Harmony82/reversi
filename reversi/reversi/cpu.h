#include "player.h"
#pragma once
class cpu :public player
{
public:
	cpu();
	void cpu_put(board &board);
	vector2int cpu_thinking(board board);
};
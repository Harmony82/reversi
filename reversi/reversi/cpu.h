#include "player.h"
#pragma once
class cpu :public player
{
public:
	cpu();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="board"></param>
	/// <returns>パスすることなく置けたかどうか</returns>
	bool cpu_put(board &board);
private:
	vector2int cpu_thinking(board board);
};
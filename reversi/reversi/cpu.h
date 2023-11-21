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
	/// <returns>ƒpƒX‚·‚é‚±‚Æ‚È‚­’u‚¯‚½‚©‚Ç‚¤‚©</returns>
	bool cpu_put(board &board);
private:
	vector2int cpu_thinking(board board);
};
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
	/// <returns>�p�X���邱�ƂȂ��u�������ǂ���</returns>
	bool cpu_put(board &board);
private:
	vector2int cpu_thinking(board board);
};
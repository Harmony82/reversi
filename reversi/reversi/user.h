#include "player.h"
#pragma once
class user :public player
{
public:
	user();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="board"></param>
	/// <returns>�p�X���邱�ƂȂ��u�������ǂ���</returns>
	bool user_put(board &board);
};
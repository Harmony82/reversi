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
	/// <returns>パスすることなく置けたかどうか</returns>
	bool user_put(board &board);
};
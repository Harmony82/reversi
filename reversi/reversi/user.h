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
	/// <returns>ƒpƒX‚·‚é‚±‚Æ‚È‚­’u‚¯‚½‚©‚Ç‚¤‚©</returns>
	bool user_put(board &board);
};
#pragma once
#include"weapon.h"
#include <ctime>


class dragonsword : public weapon
{
	
public:
	dragonsword();
	void weaponskills(monster *m);
public:
	//晕眩几率
	int stunrate;
	//晕眩回合
	int stunround;
};
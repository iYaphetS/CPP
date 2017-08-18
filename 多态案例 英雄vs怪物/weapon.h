#pragma once
#include <iostream>
using namespace std;
#include "monster.h"


class weapon
{
public:
	
	int getBasedamage();
	int getBasecritdamage();
	int getBasecritrate();
	int getBaseevasionrate();
	string getname();
	virtual void weaponskills(monster *m);
	virtual ~weapon();
public:
	//基础伤害
	int Basedamage;
	//基础暴击伤害加成
	int Basecritdamage;
	//基础暴击发生概率
	int Basecritrate;
	//基础闪避几率
	int Baseevasionrate;
	//武器名称
	string name;
};
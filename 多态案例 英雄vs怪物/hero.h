#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "weapon.h"
#include "monster.h"

class hero
{
public:
	hero();
	void heroequipweapon(weapon *w);
	int heroattackmonster(monster *m);
	bool iscrit();

public:
	//血量
	int Basehp;
	//防御
	int Baseefense;
	//基础攻击力
	int Basedamage;
	//暴击率
	int Basecritrate;
	//暴击伤害
	int Basedcritdamage;
	//躲闪率
	int Baseevasionrate;
	//武器
	weapon *pWeapon;
	//名字
	string name;
};
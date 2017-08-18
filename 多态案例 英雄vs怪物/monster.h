#pragma once
#include <iostream>
using namespace std;
#include <string>

class hero;
class monster
{
public:
	monster();
	int monsterattackhero(hero *h);

public:
	//基础血量
	int Basehp;
	//基础防御
	int Basedefense;
	//基础攻击
	int Basedamage;
	//晕眩回合
	int stunround;
	//攻击miss
	bool attackmiss;
	//名字
	string name;
};
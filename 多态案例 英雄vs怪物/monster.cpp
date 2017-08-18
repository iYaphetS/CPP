#include "monster.h"
#include "hero.h"
#include <ctime>


monster::monster()
{

	//基础血量
	Basehp = 5000;
	//基础防御
	Basedefense = 100;
	//基础攻击
	Basedamage = 300;
	//眩晕回合数
	stunround = 0;
	//攻击miss
	attackmiss = false;
	//名字
	name = "puge";
}
int monster::monsterattackhero(hero *h)
{
	if (stunround > 0)
	{
		cout << "怪物" << this->name << "处于眩晕状态，本轮无法攻击!" << endl;
		stunround--;
		cout << "英雄血量：" << h->Basehp << endl;
		return h->Basehp;
	}	
	else if (attackmiss)
	{
		cout << "怪物" << name << "攻击miss!" << endl;
		cout << "英雄血量：" << h->Basehp << endl;
		attackmiss = false;
		return h->Basehp;
	}
	int totaldamge = 0;
	totaldamge += Basedamage - h->Baseefense;

	h->Basehp -= totaldamge;

	cout << "怪物" << name << "对英雄" << h->name << "造成" << totaldamge << "点伤害!" << endl;

	cout << "英雄血量：" << h->Basehp << endl;
	return h->Basehp;
}


#include "hero.h"
#include <ctime>

hero::hero()
{
	//血量
	Basehp = 2000;
	//防御
	Baseefense = 80;
	//基础攻击力
	Basedamage = 300;
	//暴击率
	Basecritrate = 0;
	//暴击伤害加成
	Basedcritdamage = 0;
	//躲闪率
	Baseevasionrate = 0;
	//武器
	pWeapon = NULL;
	//名字
	name = "invoker";
}
void hero::heroequipweapon(weapon *w)
{
	if (this->pWeapon == w)
	{
		return;
	}
	if (this->pWeapon != NULL)
	{
		this->Basedamage -= this->pWeapon->getBasedamage();
		this->Basecritrate -= this->pWeapon->getBasecritrate();
		this->Basedcritdamage -= this->pWeapon->getBasecritdamage();
		this->Baseevasionrate -= this->pWeapon->getBaseevasionrate();
	}
	this->pWeapon = w;
	//装备新武器后的英雄属性变化
	this->Basedamage += this->pWeapon->getBasedamage();
	this->Basecritrate += this->pWeapon->getBasecritrate();
	this->Basedcritdamage += this->pWeapon->getBasecritdamage();
	this->Baseevasionrate += this->pWeapon->getBaseevasionrate();
}
int hero::heroattackmonster(monster *m)
{
	if (this->pWeapon != NULL)
	{
		this->pWeapon->weaponskills(m);
	}

	int totaldamage = Basedamage;
	if (iscrit())
	{
		cout << "暴击!" << endl;
		totaldamage += totaldamage * (Basedcritdamage / 100);
	}

	totaldamage -= m->Basedefense;
	m->Basehp -= totaldamage;

	cout << "英雄" << name << "对怪物" << m->name << "造成了" << totaldamage << "点伤害!" << endl;
	cout << "怪物血量：" << m->Basehp << endl;
	return m->Basehp;
}

bool hero::iscrit()
{
	srand((unsigned)time(NULL));

	int rate = rand() % 100;

	if (rate < Basecritrate)
	{
		return true;
	}
	return false;
}
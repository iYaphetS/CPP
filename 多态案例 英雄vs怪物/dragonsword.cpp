#include "dragonsword.h"
#include <ctime>


dragonsword::dragonsword()
{
	//基础伤害
	Basedamage = 30;
	//基础暴击伤害加成
	Basecritdamage = 100;
	//基础暴击发生概率
	Basecritrate = 40;
	//基础闪避几率
	Baseevasionrate = 30;
	//武器名称
	name = "屠龙刀";
	//晕眩几率
	stunrate = 20;
	//晕眩回合
	stunround = 1;
}


void dragonsword::weaponskills(monster *m)
{
	srand((unsigned int)time(NULL));

	int rate1 = rand() % 100 + 1;
	int rate2 = rand() % 100 + 1;

	if (stunrate > rate1)
	{
		m->stunround = this->stunround;
	}
	
	if (Baseevasionrate > rate2)
	{
		m->attackmiss = true;
	}
	

}

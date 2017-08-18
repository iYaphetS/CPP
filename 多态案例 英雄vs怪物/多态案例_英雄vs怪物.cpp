#include <iostream>
using namespace std;
#include "hero.h"
#include "dragonsword.h"
#include "woodensword.h"
#include "weapon.h"
#include "monster.h"

void test()
{
	hero h1;
	monster m1;

	woodensword wword;
	dragonsword dword;

	int round = 1;
	cout << "请选择你的武器(1--木剑 2--龙刀):";
	int id;
	cin >> id;
	if (id == 1)
	{
		h1.heroequipweapon(&wword);
	}
	else
	{
		h1.heroequipweapon(&dword);
	}
	while (true)
	{
		getchar();
		system("cls");
		cout << "第" << round << "回合" << endl;
		int ret = h1.heroattackmonster(&m1);
		if (ret <= 0)
		{
			cout << "恭喜你通关" << endl;
			break;
		}

		ret = m1.monsterattackhero(&h1);
		if (ret <= 0)
		{
			cout << "充值让你变得更强" << endl;
			break;
		}
		round++;
	}
}
int main()
{
	test();
	return 0;
}
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
	cout << "��ѡ���������(1--ľ�� 2--����):";
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
		cout << "��" << round << "�غ�" << endl;
		int ret = h1.heroattackmonster(&m1);
		if (ret <= 0)
		{
			cout << "��ϲ��ͨ��" << endl;
			break;
		}

		ret = m1.monsterattackhero(&h1);
		if (ret <= 0)
		{
			cout << "��ֵ�����ø�ǿ" << endl;
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
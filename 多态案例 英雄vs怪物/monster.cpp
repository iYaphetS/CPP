#include "monster.h"
#include "hero.h"
#include <ctime>


monster::monster()
{

	//����Ѫ��
	Basehp = 5000;
	//��������
	Basedefense = 100;
	//��������
	Basedamage = 300;
	//ѣ�λغ���
	stunround = 0;
	//����miss
	attackmiss = false;
	//����
	name = "puge";
}
int monster::monsterattackhero(hero *h)
{
	if (stunround > 0)
	{
		cout << "����" << this->name << "����ѣ��״̬�������޷�����!" << endl;
		stunround--;
		cout << "Ӣ��Ѫ����" << h->Basehp << endl;
		return h->Basehp;
	}	
	else if (attackmiss)
	{
		cout << "����" << name << "����miss!" << endl;
		cout << "Ӣ��Ѫ����" << h->Basehp << endl;
		attackmiss = false;
		return h->Basehp;
	}
	int totaldamge = 0;
	totaldamge += Basedamage - h->Baseefense;

	h->Basehp -= totaldamge;

	cout << "����" << name << "��Ӣ��" << h->name << "���" << totaldamge << "���˺�!" << endl;

	cout << "Ӣ��Ѫ����" << h->Basehp << endl;
	return h->Basehp;
}


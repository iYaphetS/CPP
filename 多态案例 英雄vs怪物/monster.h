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
	//����Ѫ��
	int Basehp;
	//��������
	int Basedefense;
	//��������
	int Basedamage;
	//��ѣ�غ�
	int stunround;
	//����miss
	bool attackmiss;
	//����
	string name;
};
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
	//�����˺�
	int Basedamage;
	//���������˺��ӳ�
	int Basecritdamage;
	//����������������
	int Basecritrate;
	//�������ܼ���
	int Baseevasionrate;
	//��������
	string name;
};
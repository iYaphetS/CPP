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
	//»ù´¡ÑªÁ¿
	int Basehp;
	//»ù´¡·ÀÓù
	int Basedefense;
	//»ù´¡¹¥»÷
	int Basedamage;
	//ÔÎÑ£»ØºÏ
	int stunround;
	//¹¥»÷miss
	bool attackmiss;
	//Ãû×Ö
	string name;
};
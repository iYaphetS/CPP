#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "weapon.h"
#include "monster.h"

class hero
{
public:
	hero();
	void heroequipweapon(weapon *w);
	int heroattackmonster(monster *m);
	bool iscrit();

public:
	//ÑªÁ¿
	int Basehp;
	//·ÀÓù
	int Baseefense;
	//»ù´¡¹¥»÷Á¦
	int Basedamage;
	//±©»÷ÂÊ
	int Basecritrate;
	//±©»÷ÉËº¦
	int Basedcritdamage;
	//¶ãÉÁÂÊ
	int Baseevasionrate;
	//ÎäÆ÷
	weapon *pWeapon;
	//Ãû×Ö
	string name;
};
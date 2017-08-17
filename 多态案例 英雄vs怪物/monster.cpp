#include "monster.h"
#include "hero.h"
#include <ctime>


monster::monster()
{

	//»ù´¡ÑªÁ¿
	Basehp = 5000;
	//»ù´¡·ÀÓù
	Basedefense = 100;
	//»ù´¡¹¥»÷
	Basedamage = 300;
	//Ñ£ÔÎ»ØºÏÊý
	stunround = 0;
	//¹¥»÷miss
	attackmiss = false;
	//Ãû×Ö
	name = "puge";
}
int monster::monsterattackhero(hero *h)
{
	if (stunround > 0)
	{
		cout << "¹ÖÎï" << this->name << "´¦ÓÚÑ£ÔÎ×´Ì¬£¬±¾ÂÖÎÞ·¨¹¥»÷!" << endl;
		stunround--;
		cout << "Ó¢ÐÛÑªÁ¿£º" << h->Basehp << endl;
		return h->Basehp;
	}	
	else if (attackmiss)
	{
		cout << "¹ÖÎï" << name << "¹¥»÷miss!" << endl;
		cout << "Ó¢ÐÛÑªÁ¿£º" << h->Basehp << endl;
		attackmiss = false;
		return h->Basehp;
	}
	int totaldamge = 0;
	totaldamge += Basedamage - h->Baseefense;

	h->Basehp -= totaldamge;

	cout << "¹ÖÎï" << name << "¶ÔÓ¢ÐÛ" << h->name << "Ôì³É" << totaldamge << "µãÉËº¦!" << endl;

	cout << "Ó¢ÐÛÑªÁ¿£º" << h->Basehp << endl;
	return h->Basehp;
}


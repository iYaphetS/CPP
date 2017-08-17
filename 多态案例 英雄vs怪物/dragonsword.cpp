#include "dragonsword.h"
#include <ctime>


dragonsword::dragonsword()
{
	//»ù´¡ÉËº¦
	Basedamage = 30;
	//»ù´¡±©»÷ÉËº¦¼Ó³É
	Basecritdamage = 100;
	//»ù´¡±©»÷·¢Éú¸ÅÂÊ
	Basecritrate = 40;
	//»ù´¡ÉÁ±Ü¼¸ÂÊ
	Baseevasionrate = 30;
	//ÎäÆ÷Ãû³Æ
	name = "ÍÀÁúµ¶";
	//ÔÎÑ£¼¸ÂÊ
	stunrate = 20;
	//ÔÎÑ£»ØºÏ
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

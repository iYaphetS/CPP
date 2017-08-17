#include "weapon.h"


int weapon::getBasedamage()
{
	return Basedamage;
}
int weapon::getBasecritdamage()
{
	return Basecritdamage;
}
int weapon::getBasecritrate()
{
	return Basecritrate;
}
int weapon::getBaseevasionrate()
{
	return Baseevasionrate;
}
string weapon::getname()
{
	return name;
}
void weapon::weaponskills(monster *m)
{

}

weapon::~weapon()
{

}
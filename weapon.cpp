#include "weapon.h"

weapon::weapon()
{
	W_item = "air";
	W_damage = 0;

}

weapon::weapon(string i, int d)
{
	W_item = i;
	W_damage = d;

}

void weapon::setItem(string i)
{
	W_item = i;
}
void weapon::setDMG(int d)
{
	W_damage = d;
}

string weapon::getItem()
{
	return W_item;
}
int weapon::getDMG()
{
	return W_damage;
}

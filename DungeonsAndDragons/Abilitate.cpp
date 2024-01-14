#include "Abilitate.h"

std::istream& operator>>(std::istream& in, Abilitate& ability)
{
	in >> ability.ability_name >> ability.damage >> ability.difficultyClass >> ability.stat_required;
	return in;
}

std::ostream& operator<<(std::ostream& out , Abilitate& ab)
{	
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 1);
	out << ab.ability_name << "\n";
	SetConsoleTextAttribute(color, 12);
	out << ab.damage << " damage" << "\n";
	SetConsoleTextAttribute(color, 14);
	out << ab.difficultyClass << " " << ab.stat_required << "\n";
	SetConsoleTextAttribute(color, 7);
	return out;
}

std::string Abilitate::getName()
{
	return ability_name;
}

int Abilitate::getDamage()
{
	return damage;
}

int Abilitate::getDifficultyClass()
{
	return difficultyClass;
}

std::string Abilitate::getStatRequired()
{
	return stat_required;
}
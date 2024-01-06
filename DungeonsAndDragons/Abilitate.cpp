#include "Abilitate.h"

std::istream& operator>>(std::istream& in, Abilitate& ability)
{
	in >> ability.ability_name >> ability.damage >> ability.difficultyClass >> ability.stat_required;
	return in;
}

std::ostream& operator<<(std::ostream& out , Abilitate& ab)
{
	out << ab.ability_name << "\n";
	out << ab.damage << " damage" << "\n";
	out << ab.difficultyClass << " " << ab.stat_required << "\n";
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
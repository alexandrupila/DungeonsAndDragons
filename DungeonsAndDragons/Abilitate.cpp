#include "Abilitate.h"

std::istream& operator>>(std::istream& in, Abilitate& ability)
{
	in >> ability.ability_name >> ability.damage >> ability.difficultyClass >> ability.stat_required;
	return in;
}

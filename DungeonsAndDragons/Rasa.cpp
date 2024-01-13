#include "Rasa.h"

std::istream& operator>>(std::istream& in, Rasa& race)
{	
	in >> race.denumire_rasa;
	std::string stat_bonus;
	int val_bonus;
	in >> val_bonus >> stat_bonus;
	race.bonus.first = stat_bonus;
	race.bonus.second = val_bonus;
	int nr_abilitati;
	in >> nr_abilitati;
	for (int i = 0; i < nr_abilitati; i++)
	{
		Abilitate temp;
		in >> temp;
		race.abiitati_rasa.push_back(temp);
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, Rasa& r)
{
	out << r.denumire_rasa << std::endl;
	out << "Bonus: " << r.bonus.first << " +" << r.bonus.second << std::endl;
	out << "Abilitati:" << std::endl;
	for (int i = 0; i < r.abiitati_rasa.size(); i++)
	{
		out << r.abiitati_rasa[i];
	}
	return out;
}

std::string Rasa::getName()
{
	return this->denumire_rasa;
}

std::vector<Abilitate> Rasa::getAbilities()
{
	return abiitati_rasa;
}

std::pair<std::string, int> Rasa::getBonus()
{
	return bonus;
}

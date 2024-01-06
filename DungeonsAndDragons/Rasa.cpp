#include "Rasa.h"

std::istream& operator>>(std::istream& in, Rasa& race)
{	
	in >> race.denumire_rasa;
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

std::string Rasa::getName()
{
	return this->denumire_rasa;
}

std::vector<Abilitate> Rasa::getAbilities()
{
	return abiitati_rasa;
}

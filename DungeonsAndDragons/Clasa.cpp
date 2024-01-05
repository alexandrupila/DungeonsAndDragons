#include "Clasa.h"

std::istream& operator>>(std::istream& in, Clasa& cl)
{
	in >> cl.denumire_clasa;
	int nr_abilitati;
	in >> nr_abilitati;
	for (int i = 0; i < nr_abilitati; i++)
	{
		Abilitate temp;
		in >> temp;
		cl.abilitati_clasa.push_back(temp);
	}
	return in;
}

std::string Clasa::getName()
{
	return denumire_clasa;
}

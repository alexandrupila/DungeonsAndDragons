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

std::ostream& operator<<(std::ostream& out, Clasa& c)
{
	out << c.denumire_clasa << std::endl;
	out << "Abilitati:" << std::endl;
	for (int i = 0; i < c.abilitati_clasa.size(); i++)
	{
		out << c.abilitati_clasa[i];
	}
	return out;
}

std::string Clasa::getName()
{
	return denumire_clasa;
}

std::vector<Abilitate> Clasa::getAbilities()
{
	return abilitati_clasa;
}

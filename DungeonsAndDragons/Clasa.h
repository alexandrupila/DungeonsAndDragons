#pragma once
#include "Abilitate.h"
#include <vector>
class Clasa
{
private:
	std::string denumire_clasa;
	std::vector<Abilitate> abilitati_clasa;
public:
	Clasa() :denumire_clasa("no_class") {}
	friend std::istream& operator>>(std::istream&, Clasa&);
};


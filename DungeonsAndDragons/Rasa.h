#pragma once
#include "Abilitate.h"
#include <vector>
#include <string>
#include <sstream>
class Rasa
{
private:
	std::string denumire_rasa;
	std::vector<Abilitate> abiitati_rasa;
public:
	Rasa() :denumire_rasa("no_race") {}
	friend std::istream& operator>>(std::istream&, Rasa&);
	std::string getName();
};


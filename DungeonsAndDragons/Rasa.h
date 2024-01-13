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
	std::pair<std::string, int> bonus;
public:
	Rasa() :denumire_rasa("no_race") {}
	friend std::istream& operator>>(std::istream&, Rasa&);
	friend std::ostream& operator<<(std::ostream&, Rasa&);
	std::string getName();
	std::vector<Abilitate> getAbilities();
	std::pair<std::string, int> getBonus();
};


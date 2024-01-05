#pragma once
#include <iostream>
class Abilitate
{
private:
	std::string ability_name;
	int damage;
	int difficultyClass;
	std::string stat_required;
public:
	Abilitate() :ability_name("NULL"), difficultyClass(0), stat_required("Strength"), damage(0) {}
	Abilitate(std::string nume, int difClass, std::string stat, int dam) : ability_name(nume), difficultyClass(difClass), stat_required(stat), damage(dam) {}
	friend std::istream& operator>>(std::istream&, Abilitate&);
};


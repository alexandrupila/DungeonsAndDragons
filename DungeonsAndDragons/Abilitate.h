#pragma once
#include <iostream>

#define NR_OF_STATS 4

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
	friend std::ostream& operator<<(std::ostream&, Abilitate&);
	std::string getName();
	int getDamage();
	int getDifficultyClass();
	std::string getStatRequired();
};


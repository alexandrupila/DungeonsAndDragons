#pragma once
#include "Rasa.h"
#include "Clasa.h"
class Personaj
{
protected:
	std::string nume;
	int hitPoints;
	Rasa rasa_personaj;
	Clasa clasa_personaj;
	std::vector<std::pair<std::string, int>> stats_personaj;
	std::string background;
public:
	Personaj():nume("nameless"), rasa_personaj(), clasa_personaj(), hitPoints(0), background("???") {}
	void setName(std::string nume_nou);
	void setHitPoints(int hp);
	void setRasa(Rasa rasa_pers);
	void setClasa(Clasa clasa_pers);
	void addStat(std::string nume_stat, int val_stat);
	void setStat(std::string nume_stat, int val_stat);
	void setTrecut(std::string trecut);
	int getHP();
	int getStatValue(std::string nume_stat);
	Rasa getRace();
	Clasa getClass();
	std::string getNume();
	Abilitate useRacialAbility(int index_abilitate);
	Abilitate useClassAbility(int index_abilitate);
	void displayEnemy();
};


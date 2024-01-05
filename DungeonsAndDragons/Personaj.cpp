#include "Personaj.h"

void Personaj::setName(std::string nume_nou)
{
	this->nume = nume_nou;
}

void Personaj::setHitPoints(int hp)
{
	this->hitPoints = hp;
}

void Personaj::setRasa(Rasa rasa_pers)
{
	this->rasa_personaj = rasa_pers;
}

void Personaj::setClasa(Clasa clasa_pers)
{
	this->clasa_personaj = clasa_pers;
}

void Personaj::addStat(std::string nume_stat, int val_stat)
{
	this->stats_personaj.push_back(std::make_pair(nume_stat, val_stat));
}

std::string Personaj::getNume()
{
	return nume;
}

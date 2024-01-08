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

void Personaj::setStat(std::string nume_stat, int val_stat)
{
	for (int i = 0; i < stats_personaj.size(); i++)
	{
		if (stats_personaj[i].first == nume_stat)
		{
			stats_personaj[i].second = val_stat;
			break;
		}
	}
}

int Personaj::getHP()
{
	return hitPoints;
}

int Personaj::getStatValue(std::string nume_stat)
{
	for (int i = 0; i < stats_personaj.size(); i++)
	{
		if (stats_personaj[i].first == nume_stat) return stats_personaj[i].second;
	}
}

Rasa Personaj::getRace()
{
	return rasa_personaj;
}

Clasa Personaj::getClass()
{
	return clasa_personaj;
}

std::string Personaj::getNume()
{
	return nume;
}

Abilitate Personaj::useRacialAbility(int index_abilitate)
{	
	std::vector<Abilitate> abilitati = rasa_personaj.getAbilities();
	return abilitati[index_abilitate];
}

Abilitate Personaj::useClassAbility(int index_abilitate)
{
	std::vector<Abilitate> abilitati = clasa_personaj.getAbilities();
	return abilitati[index_abilitate];
}

void Personaj::displayEnemy()
{
	std::cout << "Lupta cu " << this->getNume();
	std::cout << " (" << this->getHP() << " HP)" << std::endl;
}

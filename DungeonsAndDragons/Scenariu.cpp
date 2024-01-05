#include "Scenariu.h"
#include <sstream>
#include <string>
#include <fstream>
void Scenariu::readRase()
{
	std::ifstream fisier("Rase.txt");

	while (!fisier.eof())
	{
		Rasa aux;
		fisier >> aux;
		this->rase_joc.push_back(aux);
		if (fisier.eof()) break;
	}
}

void Scenariu::readClase()
{
	std::ifstream fisier("Clase.txt");

	while (!fisier.eof())
	{
		Clasa aux;
		fisier >> aux;
		this->clase_joc.push_back(aux);
		if (fisier.eof()) break;
	}
}

void Scenariu::readCamere()
{
	std::ifstream fisier("Camere.txt");

	while (!fisier.eof())
	{
		Room aux;
		
		std::string room_name;
		fisier >> room_name;
		aux.setName(room_name);

		int nr_obiecte;
		fisier >> nr_obiecte;
		for (int i = 0; i < nr_obiecte; i++)
		{
			std::string buffer;
			fisier >> buffer;
			for (int j = 0; j < this->obiecte_joc.size(); j++)
			{
				if (obiecte_joc[j]->getNume() == buffer)
				{
					aux.addObiect(obiecte_joc[j]); 
					break;
				}
			}
		}

		int nr_inamici;
		fisier >> nr_inamici;
		for (int i = 0; i < nr_inamici; i++)
		{
			std::string buffer;
			fisier >> buffer;
			for (int j = 0; j < this->inamici_joc.size(); j++)
			{
				if (inamici_joc[j].getNume() == buffer)
				{
					aux.addInamic(inamici_joc[j]);
					break;
				}
			}
		}
		
		this->camere_joc.push_back(aux);

		if (fisier.eof()) break;

	}
}

void Scenariu::readObiecte()
{
	std::ifstream fisier("Obiecte.txt");
	while (!fisier.eof())
	{
		std::string buffer;
		std::getline(fisier, buffer);
		if (buffer == "normal")
		{
			ObiectNormal* obiectNou = new ObiectNormal;
			ObiectNormal& aux = (*obiectNou);
			fisier >> aux;

			this->obiecte_joc.push_back(obiectNou);
		}
		else
		{
			ObiectSchimbareScena* obiectNou = new ObiectSchimbareScena;
			ObiectSchimbareScena& aux = (*obiectNou);
			fisier >> aux;
			this->obiecte_joc.push_back(obiectNou);
		}
	}
}

void Scenariu::readInamici()
{
	std::ifstream fisier("Inamici.txt");

	while (!fisier.eof())
	{	
		Personaj temp_pers;

		std::string nume_personaj;
		int hp_personaj;

		std::string clasa_personaj;
		std::string rasa_personaj;

		fisier >> nume_personaj;
		temp_pers.setName(nume_personaj);
		fisier >> hp_personaj;
		temp_pers.setHitPoints(hp_personaj);
		
		fisier >> rasa_personaj;
		for (int i = 0; i < this->rase_joc.size(); i++)
		{
			if (this->rase_joc[i].getName() == rasa_personaj)
			{
				temp_pers.setRasa(rase_joc[i]);
				break;
			}
		}


		fisier >> clasa_personaj;
		for (int i = 0; i < this->clase_joc.size(); i++)
		{
			if (this->clase_joc[i].getName() == clasa_personaj)
			{
				temp_pers.setClasa(clase_joc[i]);
				break;
			}
		}

		for (int i = 0; i < NR_OF_STATS; i++)
		{
			std::string stat_name;
			int stat_value;
			fisier >> stat_name >> stat_value;
			temp_pers.addStat(stat_name, stat_value);
		}

		this->inamici_joc.push_back(temp_pers);

		if (fisier.eof()) break;

	}
}

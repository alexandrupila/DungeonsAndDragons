#pragma once
#include "Rasa.h"
#include "Clasa.h"
#include "Room.h"
#include "Personaj.h"
#include "ObiectNormal.h"
#include "ObiectSchimbareScena.h"
class Scenariu
{
private:
	std::vector<Rasa> rase_joc;
	std::vector<Clasa> clase_joc;
	std::vector<Room> camere_joc;
	std::vector<IObiect*> obiecte_joc;
	std::vector<Personaj> inamici_joc;
public:
	void readRase();
	void readClase();
	void readCamere();
	void readObiecte();
	void readInamici();
	void readScenariu();
};


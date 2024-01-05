#pragma once
#include <iostream>
#include <vector>
#include "ObiectNormal.h"
#include "Personaj.h"
class Room
{
private:
	std::string room_name;
	std::vector<IObiect*> obiecte;
	std::vector<Personaj> inamici;
public:
	void addObiect(IObiect* obiectNou);
	void addInamic(Personaj inamicNou);
	void setName(std::string name);
};


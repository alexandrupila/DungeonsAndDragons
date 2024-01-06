#include "Room.h"

void Room::addObiect(IObiect* obiectNou)
{
	this->obiecte.push_back(obiectNou);
}

void Room::addInamic(Personaj inamicNou)
{
	this->inamici.push_back(inamicNou);
}

void Room::setName(std::string name)
{
	this->room_name = name;
}

void Room::removeEnemy(Personaj inamic)
{
	for (int i = 0; i < inamici.size(); i++)
	{
		if (inamici[i].getNume() == inamic.getNume())
		{
			inamici.erase(inamici.begin() + i);
			break;
		}
	}
}

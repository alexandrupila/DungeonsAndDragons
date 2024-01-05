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

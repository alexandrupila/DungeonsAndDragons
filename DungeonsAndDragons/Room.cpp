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

void Room::removeObject(IObiect* obiect)
{
	for (int i = 0; i < obiecte.size(); i++)
	{
		if (obiect->getNume() == obiecte[i]->getNume())
		{
			obiecte.erase(obiecte.begin() + i);
			break;
		}
	}
}

std::vector<IObiect*> Room::getObiecte()
{
	return obiecte;
}

std::vector<Personaj> Room::getInamici()
{
	return inamici;
}

std::string Room::getRoomName()
{
	return this->room_name;
}

std::ostream& operator<<(std::ostream& out , Room& r)
{
	out << "Camera: " << r.room_name << std::endl;
	out << "In camera se afla urmatoarele :" << std::endl;

	for (int i = 0; i <r.obiecte.size();i++)
	{	
		std::cout << i + 1 << ".:";
		r.obiecte[i]->displayObiect();
	}

	for (int i = r.obiecte.size(); i < r.obiecte.size() + r.inamici.size(); i++)
	{
		std::cout << i + 1 << ".:";
		r.inamici[i-r.obiecte.size()].displayEnemy();
	}

	return out;
}

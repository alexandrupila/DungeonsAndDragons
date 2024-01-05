#include "ObiectNormal.h"

std::istream& operator>>(std::istream& in, ObiectNormal& obj)
{	
	std::string line;
	std::getline(in, line);
	std::stringstream linestream(line);
	linestream >> obj.nume_obiect >> obj.difficultyClass >> obj.stat_required;

	std::getline(in, obj.interactiune);
	return in;
}

void ObiectNormal::interactioneaza()
{
	std::cout << "nimic";
}

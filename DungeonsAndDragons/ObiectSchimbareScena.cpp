#include "ObiectSchimbareScena.h"

std::istream& operator>>(std::istream& in, ObiectSchimbareScena& obj)
{
	std::string line;
	std::getline(in, line);
	std::stringstream linestream(line);
	linestream >> obj.nume_obiect >> obj.difficultyClass >> obj.stat_required;

	std::getline(in, obj.nume_camera_noua);
    return in;
}

void ObiectSchimbareScena::interactioneaza()
{
    std::cout << "nimic";
}

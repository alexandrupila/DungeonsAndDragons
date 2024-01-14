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
	Logger::getInstance().logBlueMessage("Ai folosit <" + this->getNume() + "> si ai ajuns in " + this->nume_camera_noua + '\n');
}

void ObiectSchimbareScena::displayObiect()
{
	std::cout << "Interactioneaza cu <" << this->getNume() << ">";
	std::cout << " (" << this->getDifficultyClass() << " " << this->getStat() << ")" << std::endl;
}

std::string ObiectSchimbareScena::getNewRoomName()
{
	return nume_camera_noua;
}

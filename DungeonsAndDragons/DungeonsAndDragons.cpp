#include <iostream>
#include <fstream>
#include "Rasa.h"
#include "Clasa.h"
#include "Scenariu.h"

int main()
{
	Scenariu s;
	s.readRase();
	s.readClase();
	s.readObiecte();
	s.readInamici();
	s.readCamere();

	std::cout << "A";
}


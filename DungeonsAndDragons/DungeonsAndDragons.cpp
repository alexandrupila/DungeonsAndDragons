#include <iostream>
#include <fstream>
#include "Rasa.h"
#include "Clasa.h"
#include "Scenariu.h"
#include "DungeonMaster.h"
int main()
{
	DungeonMaster dm;

	dm.initGame();
	dm.test();

	std::cout << "A";

	return 0;
}


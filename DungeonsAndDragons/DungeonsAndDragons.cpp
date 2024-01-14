#include <iostream>
#include <fstream>
#include "Rasa.h"
#include "Clasa.h"
#include "Scenariu.h"
#include "DungeonMaster.h"
int main()
{
	DungeonMaster dm = DungeonMaster::getInstance();
	dm.playGame();

	return 0;
}


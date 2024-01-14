#pragma once
#include "Scenariu.h"
#include "Dice.h"
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
class DungeonMaster
{
private:
	Personaj player_joc;
	Scenariu scenariu_joc;
	Dice zar;
	Room* current_room;
	static DungeonMaster* instance;
	DungeonMaster();
public:
	void displayStartMessage();
	void createPlayerCharacter();
	void initGame();
	void fightEnemy(Personaj inamic);
	void interactWithRoom();
	void setNewRoom(std::string newRoomName);
	int calculateDiceResult(int difficultyClass, int statValue,std::string stat);
	void test();
	void playGame();
	static DungeonMaster& getInstance();
	static void destroyInstance();
};


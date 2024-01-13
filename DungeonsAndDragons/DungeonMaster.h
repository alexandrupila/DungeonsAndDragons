#pragma once
#include "Scenariu.h"
#include "Dice.h"
#include <stdlib.h>
#include <Windows.h>
class DungeonMaster
{
private:
	Personaj player_joc;
	Scenariu scenariu_joc;
	Dice zar;
	Room* current_room;
public:
	void createPlayerCharacter();
	void initGame();
	void fightEnemy(Personaj inamic);
	void interactWithRoom();
	void setNewRoom(std::string newRoomName);
	int calculateDiceResult(int difficultyClass, int statValue,std::string stat);
	void test();
	void playGame();
	DungeonMaster();
};


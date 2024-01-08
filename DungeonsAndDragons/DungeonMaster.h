#pragma once
#include "Scenariu.h"
#include "Dice.h"
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
	int calculateDiceResult(int difficultyClass, int statValue);
	void test();
	void playGame();
	DungeonMaster();
};


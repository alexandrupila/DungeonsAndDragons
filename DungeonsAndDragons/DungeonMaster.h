#pragma once
#include "Scenariu.h"
#include "Dice.h"
class DungeonMaster
{
private:
	Personaj player_joc;
	Scenariu scenariu_joc;
	Dice zar;
public:
	void createPlayerCharacter();
	void initGame();
	void fightEnemy(Personaj inamic);
	int calculateDiceResult(int difficultyClass, int statValue);
	void test();
};


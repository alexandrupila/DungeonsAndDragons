#include "Dice.h"
#include <stdlib.h>
#include <time.h>

int generateRandomNumber()
{
    srand(time(NULL));
    return rand();
}

int Dice::rollDice()
{
    return generateRandomNumber()%20+1;
}

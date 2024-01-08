#pragma once
#include <iostream>
class IObiect
{
public:
	virtual void interactioneaza() = 0;
	virtual std::string getNume() = 0;
	virtual std::string getStat() = 0;
	virtual int getDifficultyClass() = 0;
	virtual void displayObiect() = 0;
};


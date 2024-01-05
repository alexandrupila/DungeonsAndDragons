#pragma once
#include <iostream>
class IObiect
{
public:
	virtual void interactioneaza() = 0;
	virtual std::string getNume() = 0;
};


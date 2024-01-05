#pragma once
#include "IObiect.h"
#include <string>
#include <sstream>
#include <iostream>
class Obiect :
    public IObiect
{
protected:
    std::string nume_obiect;
    int difficultyClass;
    std::string stat_required;
public:
    virtual ~Obiect() {};
    std::string getNume() { return nume_obiect; }
};


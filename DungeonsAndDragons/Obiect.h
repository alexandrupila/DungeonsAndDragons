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
    std::string getStat() { return this->stat_required; }
    int getDifficultyClass() { return this->difficultyClass; }
    std::string getNume() { return nume_obiect; }
};


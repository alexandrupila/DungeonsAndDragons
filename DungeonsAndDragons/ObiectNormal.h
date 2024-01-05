#pragma once
#include "Obiect.h"
class ObiectNormal :
    public Obiect
{
private:
    std::string interactiune;
public:
    void interactioneaza() override;
    friend std::istream& operator>>(std::istream&, ObiectNormal&);
};


#pragma once
#include "Obiect.h"
class ObiectSchimbareScena :
    public Obiect
{
private:
    std::string nume_camera_noua;
public:
    void interactioneaza() override;
    void displayObiect() override;
    std::string getNewRoomName();
    friend std::istream& operator>>(std::istream&, ObiectSchimbareScena&);
};


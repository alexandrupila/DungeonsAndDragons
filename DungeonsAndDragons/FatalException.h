#pragma once
#include "IException.h"
#include <iostream>
class FatalException :
    public IException
{
protected:
    std::string exceptionText;
public:
    FatalException(std::string text="Fatal exception!"): exceptionText(text) {}
    void printException() override;
};


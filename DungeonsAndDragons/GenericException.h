#pragma once
#include "IException.h"
#include <iostream>
class GenericException :
    public IException
{
private:
    std::string exceptionText;
public:
    GenericException(std::string aux = "unhandled exception");
    void printException() override;
};


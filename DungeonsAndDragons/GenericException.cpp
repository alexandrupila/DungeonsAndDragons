#include "GenericException.h"

GenericException::GenericException(std::string aux)
{
	this->exceptionText = aux;
}

void GenericException::printException()
{
	std::cout << this->exceptionText << std::endl;
}

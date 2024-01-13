#include "GenericException.h"

GenericException::GenericException(std::string aux)
{
	this->exceptionText = aux;
}

void GenericException::printException()
{	
	Logger::getInstance().logMessage(this->exceptionText + "\n");
}

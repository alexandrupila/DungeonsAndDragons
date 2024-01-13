#include "FatalException.h"

void FatalException::printException()
{
	Logger::getInstance().logMessage(this->exceptionText + "\n");
	exit(0);
}

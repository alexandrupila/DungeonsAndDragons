#include "Logger.h"

Logger* Logger::instance = nullptr;

Logger& Logger::getInstance()
{
    if (Logger::instance == nullptr)
    {
        Logger::instance = new Logger();
    }
    return (*Logger::instance);
}

void Logger::destroyInstance()
{
    if (Logger::instance)
    {
        delete Logger::instance;
        Logger::instance = nullptr;
    }
}

void Logger::logMessage(std::string message)
{
    std::cout << message;
}

#include "Logger.h"

Logger* Logger::instance = nullptr;
HANDLE Logger::color = GetStdHandle(STD_OUTPUT_HANDLE);

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
    SetConsoleTextAttribute(color, 7);
    std::cout << message;
}

void Logger::logRedMessage(std::string message)
{
    SetConsoleTextAttribute(color, 12);
    std::cout << message;
    SetConsoleTextAttribute(color, 7);
}

void Logger::logGreenMessage(std::string message)
{
    SetConsoleTextAttribute(color, 10);
    std::cout << message;
    SetConsoleTextAttribute(color, 7);
}

void Logger::logBlueMessage(std::string message)
{
    SetConsoleTextAttribute(color, 1);
    std::cout << message;
    SetConsoleTextAttribute(color, 7);
}
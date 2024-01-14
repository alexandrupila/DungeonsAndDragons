#pragma once
#include <iostream>
#include "Windows.h"
class Logger
{
public:
	static HANDLE color;
	static Logger& getInstance();
	static void destroyInstance();
	static void logMessage(std::string message);
	static void logRedMessage(std::string message);
	static void logGreenMessage(std::string message);
	static void logBlueMessage(std::string message);
private:
	static Logger* instance;
	Logger() {};
	~Logger() {};

};


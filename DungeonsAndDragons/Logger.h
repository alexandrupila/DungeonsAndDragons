#pragma once
#include <iostream>
class Logger
{
public:
	static Logger& getInstance();
	static void destroyInstance();
	static void logMessage(std::string message);
private:
	static Logger* instance;
	Logger() {};
	~Logger() {};

};


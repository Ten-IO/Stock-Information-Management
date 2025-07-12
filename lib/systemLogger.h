#ifndef SYSTEMLOGGER_H
#define SYSTEMLOGGER_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum LogLevel
{
    INFO,
    WARNING,
    ERROR
};
void logHere(const std::string &file, LogLevel codeLevel, const std::string &message)
{
    std::ofstream LogFile(file, std::ios::app);
    if (LogFile.is_open())
    {
        LogFile << "[" << TimeCall()
                << "] - " << __FILE__ << ":" << __LINE__ << " : " << message << std::endl;
        LogFile.close();
    }
    else
        std::cerr << "Error: Cannot append to log file.\n";
}

// allocate machine time, covert to local, format raw-string cpy
std::string TimeCall()
{
    time_t now = time(nullptr);
    struct tm TimeStruct = *localtime(&now);
    char buffer[80] = {};
    strftime(buffer, 80, "%a %b %Y-%T %Z", &TimeStruct);
    return std::string(buffer);
}

#endif
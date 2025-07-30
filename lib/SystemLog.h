#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

/**
 * @class FileLog
 * @brief logger for debug
 */
class FileLog
{
public:
    std::string fileName;

    FileLog(const std::string &initName)
    {
        setName(initName);
        std::ifstream LogFile(fileName);
        if (!LogFile.is_open())
            throw std::runtime_error("[!] could not located/read file\n");
    }

    // setter
    void setName(const std::string &initName)
    {
        fileName = initName;
    }
    // getter
    std::string getName()
    {
        return fileName;
    }

    // Level for passing during log
    enum LogLevel
    {
        INFO,
        WARNING,
        ERROR
    };

    /**
     * @brief message logger
     * @param codeLevel info, warning, error
     * @param message to log
     * return void
     */
    void logHere(LogLevel codeLevel, const std::string &message)
    {
        std::ofstream LogFile(fileName, std::ios::app);
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
};
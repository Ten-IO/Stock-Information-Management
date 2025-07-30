#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
        {
            std::ofstream init(fileName);
            std::cout << "[+] Start clean log\n";
            init.close();
        }
        else
            std::cout << "[+] Log file confirmed";
        LogFile.close();
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
        IMPORT,
        EXPORT,
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

    std::string levelToStr(LogLevel lvl)
    {
        switch (lvl)
        {
        case LogLevel::IMPORT:
            return "import";
        case LogLevel::EXPORT:
            return "export";
        case LogLevel::INFO:
            return "info";
        case LogLevel::WARNING:
            return "warning";
        case LogLevel::ERROR:
            return "ERROR";
        default:
            return "[!] Faulty LogLvL";
        }
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
    void getCurrentDateTime(std::string &dateStr, std::string &timeStr)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        char dateBuf[11], timeBuf[9];
        strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", ltm);
        strftime(timeBuf, sizeof(timeBuf), "%H:%M:%S", ltm);
        dateStr = dateBuf;
        timeStr = timeBuf;
    }
    bool checkHeader(const std::string &line, const std::string header[], int size)
    {
        std::stringstream ss(line);
        std::string field;
        for (int i = 0; i < size; i++)
        {
            if (!std::getline(ss, field, ',') || field != header[i])
                return 0;
        }
        return 1;
    }

    void writeLog(const int &id, const std::string &name, const int &units, const std::string &user, LogLevel LOG)
    {
        const std::string LOG_HEADER[] = {"id", "product name", "units", "user", "activity", "date", "time"};
        const size_t LOG_HEADER_SZ = sizeof(LOG_HEADER) / sizeof(LOG_HEADER[0]);

        std::ofstream WriteFile(fileName, std::ios::app);
        std::ifstream ReadFile(fileName);

        std::string line;
        std::getline(ReadFile, line);
        if (!checkHeader(line, LOG_HEADER, LOG_HEADER_SZ))
        {
            for (size_t i = 0; i < LOG_HEADER_SZ; ++i)
            {
                WriteFile << LOG_HEADER[i];
                if (i + 1 < LOG_HEADER_SZ)
                    WriteFile << ",";
            }
            WriteFile << "\n";
        }

        if (!WriteFile.is_open())
        {
            std::cerr << "[!] Error: Could not open " << fileName << ".csv\n";
            return;
        }

        std::string dateStr, timeStr;
        getCurrentDateTime(dateStr, timeStr);

        WriteFile << id << "," << name << "," << units << "," << user << "," << levelToStr(LOG) << "," << dateStr << "," << timeStr << "\n";
        WriteFile.close();
    }
};
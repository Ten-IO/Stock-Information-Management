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
        {
            std::ofstream init(fileName);
            std::cout << "\n[+] Start clean log\n";
            init.close();
        }
        else
            std::cout << "\n[+] Log file confirmed\n";
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
        ERR,
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
        case LogLevel::ERR:
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

    void writeLog(int id, const std::string &name, int units, const double &price, const std::string &user, LogLevel LOG)
    {
        const std::string LOG_HEADER[] = {"id", "product name", "units", "price", "activity", "user", "date", "time"};
        const size_t LOG_HEADER_SZ = sizeof(LOG_HEADER) / sizeof(LOG_HEADER[0]);

        std::ofstream WriteFile(fileName, std::ios::app);
        std::ifstream ReadFile(fileName);

        std::string line;
        std::getline(ReadFile, line);
        if (!checkHeader(line, LOG_HEADER, LOG_HEADER_SZ))
        {
            std::ofstream NewFile(fileName);
            std::cerr << "\n[!] Wrong header: " << line << "\n[!] Cleaning File - Initialize new one";

            for (size_t i = 0; i < LOG_HEADER_SZ; ++i)
            {
                NewFile << LOG_HEADER[i];
                if (i + 1 < LOG_HEADER_SZ)
                    NewFile << ",";
            }
            NewFile << "\n";
            NewFile.close();
        }
        ReadFile.close();

        if (!WriteFile.is_open())
        {
            std::cerr << "\n[!] Error: Could not open " << fileName << ".csv\n";
            return;
        }

        std::string dateStr, timeStr;
        getCurrentDateTime(dateStr, timeStr);

        WriteFile << id << "," << name << "," << units << "," << price << "," << levelToStr(LOG) << "," << user << ',' << dateStr << "," << timeStr << "\n";
        WriteFile.close();
    }

    List *readLog()
    {

        std::string line, blk[6];
        int col;
        List *ls = new List();

        const std::string LOG_HEADER[] = {"id", "product name", "units", "price", "activity", "user", "date", "time"};
        int LOG_HEADER_SZ = sizeof(LOG_HEADER) / sizeof(LOG_HEADER[0]);
        std::ifstream ReadFile(fileName);
        std::getline(ReadFile, line);
        if (!checkHeader(line, LOG_HEADER, LOG_HEADER_SZ))
        {
            ReadFile.close();
            std::cout << "\n[-] " << fileName << " Header problems..\n";
        }

        std::stringstream ss(line);
        std::string token;
        col = 0;
        while (std::getline(ss, token, ',') && col < 6)
        {
            blk[col++] = token;
        }
        while (std::getline(ReadFile, line))
        {
            col = 0;
            blk[0].clear(), blk[1].clear(), blk[2].clear(), blk[3].clear(), blk[4].clear(), blk[5].clear();
            for (char c : line)
            {
                if (c == ',')
                {
                    col++;
                    if (col == 6)
                        break;
                }
                else
                    blk[col] += c;
            }
            blk[4] += std::string(" by ") + blk[5];
            ls->addItem(Item{std::stoi(blk[0]), std::stoi(blk[2]), blk[1], blk[4], std::stod(blk[3])});
        }
        ReadFile.close();
        return ls;
    }
};
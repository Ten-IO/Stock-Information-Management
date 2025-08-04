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
private:
    std::string __fileName;

public:
    enum LogLevel
    {
        IMPORT,
        EXPORT,
        INFO,
        WARNING,
        ERR,
    };

    /**
     * @brief constructor for FileName and check existence
     * @return new file if file does not exist
     */
    FileLog(const std::string &initName);

    // setter
    void setName(const std::string &initName);

    // getter
    std::string getName();
    // Level for passing during log
    /**
     * @brief message logger
     * @param codeLevel info, warning, error
     * @param message to log
     * return void : log to report log of current file and line
     */
    void logHere(LogLevel codeLevel, const std::string &message, const char *__file = __FILE__, int __line = __LINE__);

    /**
     * @brief turning log message to text
     * @param LogLevel a group of constant of log level
     * @retval `text` - log state called
     */
    std::string levelToStr(LogLevel lvl);

    /**
     * @brief machine time, covert to local, format raw-string cpy - date,time,locale region
     * @retval ddd mmm yyyy-hh:mm:ss-timezone
     * @example : Date-time: Mon Aug 2025-10:40:41 SE Asia Standard Time
     */
    std::string TimeCall();

    /**
     * @brief machine time, format - date,time
     * @retval yyyy-mm-dd hh:mm:ss
     * @example : time: 2025-08-04 11:15:22
     */
    void getCurrentDateTime(std::string &dateStr, std::string &timeStr);

    /**
     * @brief verify header, if fail, reset file output file
     * @param line first line from ifstream getline @param header arrays of column names @param size amount of columns
     * @retval `true` column is correct, does not reset log file @retval `false` column incorrect, reset
     */
    bool checkHeader(const std::string &line, const std::string header[], int size);

    /**
     * @brief report user activity information
     * @param id of item @param name of item @param units of item @param price of item @param user of current system @param LOG of activity from user
     * @return output to a file, recording information logs of input parameters
     */
    void writeLog(int id, const std::string &name, int units, const double &price, const std::string &user, LogLevel LOG);
    
    /**
     * @brief read report in and summarize
     * @retval List : of report information format of id,product name,units,price,activity,user
     */
    List *readLog();
};

FileLog::FileLog(const std::string &initName)
{
    setName(initName);
    std::ifstream LogFile(__fileName);
    if (!LogFile.is_open())
    {
        std::ofstream init(__fileName);
        std::cout << "\n[+] Start clean log\n";
        init.close();
    }
    else
        std::cout << "\n[+] Log file confirmed\n";
    LogFile.close();
}

void FileLog::setName(const std::string &initName)
{
    __fileName = initName;
}
std::string FileLog::getName()
{
    return __fileName;
}

void FileLog::logHere(LogLevel codeLevel, const std::string &message, const char *__file, int __line)
{
    std::ofstream LogFile(__fileName, std::ios::app);
    if (LogFile.is_open())
    {
        LogFile << "[" << TimeCall() << "] " << levelToStr(codeLevel) << " - "
                << __file << ":" << __line << " : " << message << std::endl;
        LogFile.close();
    }
    else
        std::cerr << "\n[!] Error: Cannot append to log file.\n";
}

std::string FileLog::levelToStr(LogLevel lvl)
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
        return "error";
    default:
        return "[!] Faulty Log Level";
    }
}
std::string FileLog::TimeCall()
{
    time_t now = time(nullptr);
    struct tm TimeStruct = *localtime(&now);
    char buffer[80] = {};
    strftime(buffer, 80, "%a %b %Y-%T %Z", &TimeStruct);
    return std::string(buffer);
}
void FileLog::getCurrentDateTime(std::string &dateStr, std::string &timeStr)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char dateBuf[11], timeBuf[9];
    strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", ltm);
    strftime(timeBuf, sizeof(timeBuf), "%H:%M:%S", ltm);
    dateStr = dateBuf;
    timeStr = timeBuf;
}

bool FileLog::checkHeader(const std::string &line, const std::string header[], int size)
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

void FileLog::writeLog(int id, const std::string &name, int units, const double &price, const std::string &user, LogLevel LOG)
{
    const std::string LOG_HEADER[] = {"id", "product name", "units", "price", "activity", "user", "date", "time"};
    const size_t LOG_HEADER_SZ = sizeof(LOG_HEADER) / sizeof(LOG_HEADER[0]);

    std::ofstream WriteFile(__fileName, std::ios::app);
    std::ifstream ReadFile(__fileName);

    std::string line;
    std::getline(ReadFile, line);
    if (!checkHeader(line, LOG_HEADER, LOG_HEADER_SZ))
    {
        std::ofstream NewFile(__fileName);
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
        std::cerr << "\n[!] Error: Could not open " << __fileName << ".csv\n";
        return;
    }

    std::string dateStr, timeStr;
    getCurrentDateTime(dateStr, timeStr);

    WriteFile << id << "," << name << "," << units << "," << price << "," << levelToStr(LOG) << "," << user << ',' << dateStr << "," << timeStr << "\n";
    WriteFile.close();
}

List *FileLog::readLog()
{

    std::string line, blk[6];
    int col;
    List *ls = new List();

    const std::string LOG_HEADER[] = {"id", "product name", "units", "price", "activity", "user", "date", "time"};
    int LOG_HEADER_SZ = sizeof(LOG_HEADER) / sizeof(LOG_HEADER[0]);
    std::ifstream ReadFile(__fileName);
    std::getline(ReadFile, line);
    if (!checkHeader(line, LOG_HEADER, LOG_HEADER_SZ))
    {
        ReadFile.close();
        std::cout << "\n[-] " << __fileName << " Header problems..\n";
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
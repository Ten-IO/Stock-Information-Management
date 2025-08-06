#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "StockList.h"

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

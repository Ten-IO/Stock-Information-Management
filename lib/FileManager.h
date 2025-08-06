#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "StockList.h"

class FileManager
{
public:
    std::string fileName;
    std::string headers[5] = {"id", "name", "category", "unit", "unit price"};
    int header_sz = 5;

    /**
     * @brief File Storage Initializer, cleaning fileName to csv
     * @return create new clean file if does not exist
     */
    FileManager(const std::string &initName);

    /**
     * @brief check existence of file
     * @retval `true` file can be created @retval `false` file cannot be created
     * @return new File with fileName
     */
    bool initFile(const std::string &initName);

    /**
     * @brief verify for correct header
     * @retval `true` fetch column names are correct @retval `false` fetch column names are incorrect
     */
    std::string checkFile(const std::string &fileName);

    /**
     * @brief verify for correct header
     * @retval `true` fetch column names are correct @retval `false` fetch column names are incorrect
     */
    bool checkHeader(const std::string &line, const std::string header[], int size);

    /**
     * @brief List -> File, export data from program
     * @param fileName File + Location
     * @param headers attributes of information
     * @param headerSize count of headers
     * @param ls store address of List
     * @return int Code indicating result:
     * - `0` on file not able to open
     * - `1` on success file creation
     */
    bool ListToCsv(List *ls);

    /**
     * @brief File -> List, import data for program
     * @param fileName File + Location
     * @param headers attributes of information
     * @param header_sz count of headers
     * @param ls store address of List
     * @retval `1` on success file creation
     * @retval `0` on file not found
     */
    bool CsvToList(List *ls);
};
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

FileManager::FileManager(const std::string &initName)
{
    fileName = checkFile(initName);
    std::ifstream chFile(fileName);

    if (!chFile.is_open())
    {
        std::cerr << "[!] File does not exist ";
        initFile(fileName);
    }
    chFile.close();
}

bool FileManager::initFile(const std::string &initName)
{
    std::ofstream newFile(initName);
    std::cout << "[+] Create new file\n";
    if (!newFile.is_open())
    {
        throw std::runtime_error(std::string("\n[!] Cannot open the file:") + initName + "\n");
        return 0;
    }
    newFile.close();
    return 1;
}

std::string FileManager::checkFile(const std::string &fileName)
{
    std::string tmp;
    for (char c : fileName)
    {
        if (c == '.')
            return tmp + ".csv";
        else if (!((c > 47 && c < 58) || (tolower(c) > 96 && tolower(c) < 123)) && c != '_' && c != '-')
            throw std::runtime_error(std::string("\n[!] Unidentified sign located in " + fileName + ". Please remove!\n"));
        else
            tmp += c;
    }
    return fileName + ".csv";
}

bool FileManager::checkHeader(const std::string &line, const std::string header[], int size)
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

bool FileManager::ListToCsv(List *ls)
{
    std::ofstream OutFile(fileName);
    std::ifstream readHead(fileName);

    if (!readHead.is_open())
    {
        std::cerr << "[!] Can't open file\n";
        return 0;
    }

    // header access
    std::string line;
    std::getline(readHead, line);
    if (!checkHeader(line, headers, header_sz))
    {
        for (int i = 0; i < header_sz; i++)
        {
            OutFile << headers[i];
            if (i < header_sz - 1)
                OutFile << ",";
        }
        OutFile << "\n";
    }
    readHead.close();
    // data division
    Stock *current = ls->head;
    while (current != nullptr)
    {
        OutFile << current->item.id << ",";
        OutFile << current->item.name << ",";
        OutFile << current->item.category << ",";
        OutFile << current->item.units << ",";
        OutFile << current->item.unitPrice << "\n";
        current = current->next;
    }

    OutFile.close();
    return 1;
}

/**
 * @brief File -> List, import data for program
 * @param fileName File + Location
 * @param headers attributes of information
 * @param header_sz count of headers
 * @param ls store address of List
 * @retval `1` on success
 * @retval `0` on file not found
 */
bool FileManager::CsvToList(List *ls)
{
    std::ifstream InFile(fileName, std::ios::in);

    if (!InFile.is_open())
    {
        std::cerr << "[!] Cannot open to read file\n";
        return 0;
    }

    std::string line, block;
    std::stringstream ss;
    int index = 0;
    Item item;

    std::getline(InFile, line);

    while (std::getline(InFile, line))
    {
        ss.clear();
        ss.str(line);
        // parse id
        std::getline(ss, block, ',');
        item.id = std::stoi(block);
        // parse name
        std::getline(ss, item.name, ',');
        // parse category
        std::getline(ss, item.category, ',');
        // parse amount
        std::getline(ss, block, ',');
        item.units = std::stoi(block);
        // parse price
        std::getline(ss, block, ',');
        item.unitPrice = std::stod(block);
        ls->addItem(item);
        index++;
    }
    std::cout << "\n[+] Updated " << index << " to list\n";
    InFile.close();
    return 1;
}
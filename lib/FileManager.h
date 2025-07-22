#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "StockList.h"

class FileManager
{
public:
    std::string fileName;
    FileManager(const std::string &initName)
    {
        fileName = checkFile(initName);
        std::ofstream OutFile(fileName, std::ios::app | std::ios::out);

        if (!OutFile.is_open())

            throw std::runtime_error("\nCannot open the file\n");

        OutFile.close();
    }

    std::string checkFile(const std::string &fileName)
    {
        std::string tmp;
        for (char c : fileName)
        {
            if (c == '.')
                return tmp + ".csv";
            else if (!((c > 47 && c < 58) || (tolower(c) > 96 && tolower(c) < 123)) && c != '_' && c != '-')
                throw std::runtime_error("\nUnidentified sign located in file name. Please remove!\n");
            else
                tmp += c;
        }
        return fileName + ".csv";
    }
    bool checkHeader(const std::string &line, const std::string header[], int size)
    {
        std::stringstream ss(line);
        std::string field;
        for (int i = 0; i < size; i++)
        {
            if (!std::getline(ss, field, ','))
                return 0;
            if (field != header[i])
                return 0;
            return 1;
        }
    }
    /**
     * @brief List -> File, export data from program
     * @param fileName File + Location
     * @param headers attributes of information
     * @param headerSize count of headers
     * @param ls store address of List
     * @return int Code indicating result:
     * - `-1` on file not able to open
     * - `0` on success
     */
    int ListToCsv(const std::string &fileName, const std::string headers[], int headerSize, List *ls)
    {
        std::ofstream OutFile(fileName, std::ios::app | std::ios::out);
        std::ifstream readHead(fileName, std::ios::in);

        if (!OutFile.is_open())
        {
            std::cerr << "Can't open file\n";
            return -1;
        }

        // header access
        std::string line;
        std::getline(readHead, line);
        if (!checkHeader(line, headers, headerSize))
        {
            for (int i = 0; i < headerSize; i++)
            {
                OutFile << headers[i];
                if (i < headerSize - 1)
                {
                    OutFile << ",";
                }
            }
            OutFile << "\n";
        }

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
        return 0;
    }

    /**
     * @brief File -> List, import data for program
     * @param fileName File + Location
     * @param headers attributes of information
     * @param headerSize count of headers
     * @param ls store address of List
     * @retval `0` on success
     * @retval `-1` on file not found
     */
    int CsvToList(const std::string &fileName, const std::string headers[], int headerSize, List *ls)
    {
        std::ifstream InFile(fileName, std::ios::in);

        if (!InFile.is_open())
        {
            std::cerr << "Cannot open file\n";
            return -1;
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

        InFile.close();
        return 0;
    }
};

#endif
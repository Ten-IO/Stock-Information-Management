#ifndef STORAGEINFO_H
#define STORAGEINFO_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <creator.h>

void ListToCsv(string fileLocation, std::string headers[], int headerSize, List *ls);
void CsvToList(const std::string &fileLocation, const std::string headers[], int headerSize, List *ls)
{
    // void CsvToList(const std::string &fileLocation){
    std::ifstream InFile(fileLocation, std::ios::in);

    if (!InFile.is_open())
    {
        std::cerr << "Cannot open file\n";
        return;
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
        std::cerr << "Cat" << index << " " << item.category;
        addEnd(ls, item);
        index++;
    }

    InFile.close();
}

#endif
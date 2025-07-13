#ifndef STORAGEINFO_H
#define STORAGEINFO_H
#include <iostream>
#include <string>
#include <fstream>
#include <stock.h>

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

    std::string holder;
    int index = 0;
    Stock *s = new Stock;
    s->next = nullptr;

    std::cout <<index<<" "<< holder<<std::endl;
    std::getline(InFile, holder);
    std::cout <<index<<" "<< holder<<std::endl;

    while (std::getline(InFile, holder, ','))
    {
        std::cout <<index<<" "<< holder;
        switch (++index)
        {
        case 1:
            try{
            s->item.id = std::stoi(holder);
            }catch(std::exception &e){
                std::cerr<<"here";
            }
            break;
        case 2:
        s->item.name = holder;
        break;
        case 3:
        s->item.category = holder;
        break;
        case 4:
        try{
        s->item.units = std::stoi(holder);
}catch(std::exception &e){
                std::cerr<<"here2 +Value: "<<holder;
            }
            break;
        case 5:
            s->item.unitPrice = stod(holder);
            return;
            break;

        default:
            index = 0;
            ls->n++;
            ls->tail=s;
            break;
        }
    }

    InFile.close();
}

#endif
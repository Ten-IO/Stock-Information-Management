#ifndef STORAGEINFO_H
#define STORAGEINFO_H
#include <string>
#include <stock.h>

void ListToCsv(string fileLocation,std::string headers[], List *ls);
void CsvToList(string fileLocation,std::string headers[], List *ls);

#endif
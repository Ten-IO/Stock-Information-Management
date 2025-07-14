#include <iostream>
#include "storageInfo.h"
#include "createFile.h"
#include "stock.h"
#include "creator.h"
#include "displayManager.h"
int main(){
    List *ls = initList();
    addEnd(ls, Item{1,100,"NUM1","", 0.1});
    std::string header[]={"ID","Amount", "Name", "Category","Price"};
    // createCSV("log.csv",header,5,ls);
    CsvToList("test/log.csv",header,5,ls);
    std::cout<< "After log read: "<< ls->n<<std::endl;
    tableList(ls);
    // CsvToList("log.csv");
    return 100; 
}
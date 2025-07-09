#include <iostream>
#include <vector>
#include <string>
#include "stock.h"
#include "createFile.h"


void modifyViaID(List *ls, Item oldData, Item newData)
{
    Stock *s = ls->head;
    int isFound = 0;
    while (s != nullptr)
    {
        if (s->item.id == oldData.id)
        {
            s->item = newData;
            isFound += 1;
        }
        s = s->next;
    }
    
    if (isFound != 0){
	
        std::cout << "data updated\n";
        createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls);
	}
    else
        std::cout << "data unchange\n";
}

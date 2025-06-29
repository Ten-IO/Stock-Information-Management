#include <iostream>
#include <fstream>
#include <vector>
#include "stock.h"
#include "createFile.h" 
#include "filename.h"

using namespace std;

void addEnd(List *ls, Item item)
{
    Stock *s = new Stock;
    s->item = item;
    s->next = nullptr;

    if (ls->head == 0)
        ls->head = s;
    else
        ls->tail->next = s;
    ls->tail = s;
    ls->n++;
    
    ofstream importFile(IMPORT_FILE, ios::app);
    if (importFile.is_open()) {
        importFile << item.id << "," << item.name << "," << item.category << ","
                   << item.units << "," << item.unitPrice << "\n";
        importFile.close();
    }

    vector<string> header = {"ID", "Name", "Category", "Unit", "Unit price"};
    createCSV(CURRENT_FILE, header, ls);
}


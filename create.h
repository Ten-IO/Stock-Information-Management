#ifndef ADDEND_H
#define ADDEND_H
#include <fstream>
#include "stock.h"
#include "createFile.h"
#include "fileHeader.h"

void addEnd(List* ls, Item item)
{
    Stock* s = new Stock{item, nullptr};

    if (ls->head == nullptr)
        ls->head = s;
    else
        ls->tail->next = s;
    ls->tail = s;
    ls->n++;

    createCSV(IMPORT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, true);
    createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls);
}

#endif

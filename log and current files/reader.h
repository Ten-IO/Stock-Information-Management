#ifndef READER_H
#define READER_H

#include <iostream>
#include "stock.h"

using namespace std;

void displayFromMemory(List* list) {
    if (!list || list->head == nullptr) {
        cout << "No stock data available.\n";
        return;
    }

    Stock* current = list->head;
    cout << "\nID\tName\tCategory\tUnits\tUnitPrice\n";
    cout << "----------------------------------------------\n";

    while (current) {
        cout << current->item.id << "\t"
             << current->item.name << "\t"
             << current->item.category << "\t"
             << current->item.units << "\t"
             << current->item.unitPrice << "\n";
        current = current->next;
    }
    cout << "----------------------------------------------\n";
}
#endif

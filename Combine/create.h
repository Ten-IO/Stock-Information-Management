#ifndef CREATE_H
#define CREATE_H

#include <iostream>
#include <fstream>
#include "stock.h"
using namespace std;

void addEnd(List* ls, Item item, const string& CURRENT_FILE) {
    Stock* s = new Stock;
    s->item = item;
    s->next = nullptr;

    if (!ls->head)
        ls->head = s;
    else
        ls->tail->next = s;
    ls->tail = s;
    ls->n++;

    ofstream file(CURRENT_FILE, ios::app);
    if (file.is_open()) {
        file << item.id << "," << item.name << "," << item.category << "," << item.units << "," << item.unitPrice << "\n";
        file.close();
    }
}

#endif


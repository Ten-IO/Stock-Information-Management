#ifndef EXPORTBYID_H
#define EXPORTBYID_H

#include <iostream>
#include "stock.h"
#include "createFile.h"
#include "fileHeader.h"
using namespace std;

bool exportByID(List* ls, int& idOut, string& nameOut, int& qtyOut) {
    int id;
    cout << "Export a product\n";
    cout << "Enter the product ID to export: ";
    cin >> id;

    if (ls == nullptr || ls->head == nullptr) {
        cout << "No stock available.\n";
        return false;
    }

    Stock* current = ls->head;
    Stock* prev = nullptr;

    while (current != nullptr && current->item.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Item with ID " << id << " not found.\n";
        return false;
    }

    int availableUnits = current->item.units;
    cout << "Available units: " << availableUnits << "\n";
    cout << "Enter quantity to export: ";
    int exportQty;
    cin >> exportQty;

    if (exportQty <= 0) {
        cout << "Invalid export quantity.\n";
        return false;
    }

    if (exportQty > availableUnits) {
        cout << "Not enough stock to export " << exportQty << " units.\n";
        return false;
    }

    Item exportedItem = current->item;
    exportedItem.units = exportQty;

    current->item.units -= exportQty;

    if (current->item.units == 0) {
        if (prev == nullptr) {
            ls->head = current->next;
            if (current == ls->tail) ls->tail = nullptr;
        } else {
            prev->next = current->next;
            if (current == ls->tail) ls->tail = prev;
        }
        delete current;
        ls->n--;
    }
    createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls);

    idOut = id;
    nameOut = exportedItem.name;
    qtyOut = exportQty;

    cout << "Exported " << exportQty << " unit(s) of item ID " << id << ".\n";
    return true;
}

#endif

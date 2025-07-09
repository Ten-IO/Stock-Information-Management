#ifndef EXPORTBYID_H
#define EXPORTBYID_H

#include <iostream>
#include "stock.h"
#include "createFile.h"
#include "fileHeader.h"
using namespace std;

void exportByID(List* ls) {
	
	int id;
	cout << "Export a product\n";
	cout << "Enter the product ID to export: ";
	cin >> id;
	
    if (ls == nullptr || ls->head == nullptr) {
    	cout << "No stock available.\n";
        return;
    }

    Stock* current = ls->head;
    Stock* prev = nullptr;

    while (current != nullptr && current->item.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Item with ID " << id << " not found.\n";
        return;
    }

    int availableUnits = current->item.units;
    cout << "Available units: " << availableUnits << "\n";
    cout << "Enter quantity to export: ";
    int exportQty;
    cin >> exportQty;

    if (exportQty <= 0) {
        cout << "Invalid export quantity.\n";
        return;
    }

    if (exportQty > availableUnits) {
    	cout << "Not enough stock to export " << exportQty << " units.\n";
        return;
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

    
    List temp;
    temp.head = temp.tail = new Stock{exportedItem, nullptr};
    temp.n = 1;
    createCSV(EXPORT_FILE, CSV_HEADER, CSV_HEADER_SIZE, &temp, true);
    delete temp.head;

    createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls);
    cout << "Exported " << exportQty << " unit(s) of item ID " << id << ".\n";
}

#endif 

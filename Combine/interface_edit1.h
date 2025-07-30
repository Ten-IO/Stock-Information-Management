#ifndef INTERFACE_EDIT1_H
#define INTERFACE_EDIT1_H

#include <iostream>
#include <cstring>
#include "modifier.h"
#include "search.h"
#include "createFile.h"
using namespace std;

void interface_edit(List* ls, const string& CURRENT_FILE) {
    while (true) {
        system("cls");
        cout << "EDIT PRODUCT (Enter ID, 0 to exit): ";
        int idnumber; cin >> idnumber;
        if (idnumber == 0) return;

        Stock* node = searchByID(ls, idnumber);
        if (!node) { cout << "Product not found!\n"; continue; }

        Item oldData = node->item, newData = oldData;
        while (true) {
            cout << "\nCurrent:\n";
            displayProduct(newData);
            cout << "1.ID 2.Name 3.Category 4.Unit 5.Price 0.Save & Exit\nChoice: ";
            int choice; cin >> choice;
            switch (choice) {
                case 1: cout << "New ID: "; cin >> newData.id; break;
                case 2: cout << "New Name: "; cin >> newData.name; break;
                case 3: cout << "New Category: "; cin >> newData.category; break;
                case 4: cout << "New Unit: "; cin >> newData.units; break;
                case 5: cout << "New Price: "; cin >> newData.unitPrice; break;
                case 0:
                    if (memcmp(&oldData, &newData, sizeof(Item)) != 0) {
                        modifyViaID(ls, oldData, newData);
                        createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
                        cout << "Changes saved!\n";
                    }
                    return;
                default: cout << "Invalid choice.\n";
            }
        }
    }
}
#endif


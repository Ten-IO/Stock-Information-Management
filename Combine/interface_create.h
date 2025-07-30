#ifndef INTERFACE_CREATE_H
#define INTERFACE_CREATE_H

#include <iostream>
#include "create.h"
using namespace std;

void interface_create(List* ls, const string& CURRENT_FILE) {
    system("cls");
    cout << "CREATE PRODUCT\n";

    Item item;
    cout << "Product ID: ";
    cin >> item.id;
    cout << "Product name: ";
    cin >> item.name;
    cout << "Product category: ";
    cin >> item.category;
    cout << "Product unit: ";
    cin >> item.units;
    cout << "Product unit price: ";
    cin >> item.unitPrice;

    addEnd(ls, item, CURRENT_FILE);
    cout << "Product created successfully!\nPress Enter...";
    cin.ignore();
    cin.get();
}

#endif


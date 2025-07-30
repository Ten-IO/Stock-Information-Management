#ifndef INTERFACE_READ_H
#define INTERFACE_READ_H

#include <iostream>
#include "reader.h"
#include "createFile.h"
#include "sorter.h"
using namespace std;

void interface_read_user(List* ls, const string& CURRENT_FILE) {
    system("cls");
    cout << "=== DISPLAY PRODUCTS ===\n";
    displayFromFile(CURRENT_FILE);

    cout << "\nSort list? (y/n): ";
    string ans; cin >> ans;
    if (ans == "y" || ans == "Y") {
        if (ls->n == 0) {
            cout << "No items to sort.\n"; return;
        }
        Item* arr = ListToArr(ls, ls->n);
        cout << "Sort by:\n1.ID\n2.Name\n3.Unit\n4.Unit Price\nChoice: ";
        int opt; cin >> opt;
        SortField field;
        if (opt == 1) field = By_ID;
        else if (opt == 2) field = By_Name;
        else if (opt == 3) field = By_Unit;
        else if (opt == 4) field = By_UnitPrice;
        else { delete[] arr; return; }

        mergeSortArr(arr, 0, ls->n - 1, field, ASCENDING);
        List* sortedList = ArrToList(arr, ls->n);
        *ls = *sortedList;
        delete[] arr;
        createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
        displayFromFile(CURRENT_FILE);
    }
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

void interface_read_admin(List* stocklist, Loglist* loglist, const string& CURRENT_FILE) {
    system("cls");
    cout << "=== ADMIN READ MENU ===\n1. Stock List\n2. Logs\nChoice: ";
    int c; cin >> c;
    if (c == 1) displayFromFile(CURRENT_FILE);
    else if (c == 2) cout << "(Log display coming soon)\n"; // placeholder
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}
#endif


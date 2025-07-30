#ifndef INTERFACE_SEARCH_H
#define INTERFACE_SEARCH_H

#include <iostream>
#include "search.h"
using namespace std;

void interface_searchDataList(List* ls) {
    cout << "Search by ID: ";
    int id; cin >> id;
    displaySearchByID(ls, id);
    cout << "Press Enter...";
    cin.ignore(); cin.get();
}

void interface_searchLogList(Loglist* log) {
    cout << "Search logs by username: ";
    string name; cin >> name;
    searchUsername(log, name);
    cout << "Press Enter...";
    cin.ignore(); cin.get();
}
#endif


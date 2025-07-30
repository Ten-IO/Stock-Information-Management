#ifndef INTERFACE_DELETE_H
#define INTERFACE_DELETE_H

#include <iostream>
#include "stock.h"
#include "delete.h"
using namespace std;

void interface_delete(List* ls, const User& user, const string& CURRENT_FILE) {
    if (user.role != ADMIN) {
        cout << "Access denied.\n"; return;
    }
    cout << "Enter ID to delete: ";
    int id; cin >> id;
    if (delete_id(ls, id)) {
        createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
        cout << "Deleted successfully!\n";
    } else {
        cout << "ID not found.\n";
    }
}
#endif


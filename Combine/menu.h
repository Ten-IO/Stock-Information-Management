#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "interface_create.h"
#include "interface_read.h"
#include "interface_edit1.h"
#include "interface_delete.h"
#include "interface_search.h"
using namespace std;

void menu(const User& currentUser, List* stocklist, Loglist* loglist, const string& CURRENT_FILE) {
    while (true) {
        system("cls");
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create\n2. Read\n3. Edit\n4. Search\n";
        if (currentUser.role == ADMIN) cout << "5. Delete\n";
        cout << "0. Exit\n";

        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: interface_create(stocklist, CURRENT_FILE); break;
            case 2: (currentUser.role == ADMIN)
                    ? interface_read_admin(stocklist, loglist, CURRENT_FILE)
                    : interface_read_user(stocklist, CURRENT_FILE); break;
            case 3: interface_edit(stocklist, CURRENT_FILE); break;
            case 4: (currentUser.role == ADMIN)
                    ? interface_searchLogList(loglist)
                    : interface_searchDataList(stocklist); break;
            case 5: if (currentUser.role == ADMIN) interface_delete(stocklist, currentUser, CURRENT_FILE); break;
            case 0: cout << "Goodbye!\n"; return;
            default: cout << "Invalid choice.\n";
        }
    }
}
#endif


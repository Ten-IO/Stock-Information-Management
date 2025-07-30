#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include "menu.h"
#include "header.h"
using namespace std;

void login(List* stocklist, Loglist* loglist, const string& CURRENT_FILE) {

    printHeader();

    string username, password;
    Role role;

    cout << "========== LOGIN ==========\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "12345678") {
        role = ADMIN;
        cout << "Welcome Admin!\n";
    } else {
        role = USER;
        cout << "Welcome User!\n";
    }

    User currentUser;
    currentUser.role = role;
    currentUser.username = username;

    menu(currentUser, stocklist, loglist, CURRENT_FILE);
}
#endif


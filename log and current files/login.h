#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Admin {
    string username;
    string password;
    string role;
};

unordered_map<string, Admin> adminAccounts = {
    {"admin1", {"admin1", "pass123", "admin"}},
    {"admin2", {"admin2", "secure456", "admin"}},
    {"sna", {"sna", "sna123", "staff"}},
    {"roth", {"roth", "roth456", "staff"}}
};

extern string currentAdmin;
extern string currentRole;

bool login() {
    string username, password;

    cout << "=== Admin Login ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    auto it = adminAccounts.find(username);
    if (it != adminAccounts.end() && it->second.password == password) {
        currentAdmin = username;
        currentRole = it->second.role;
        cout << "? Login successful. Welcome, " << currentAdmin << " (" << currentRole << ").\n";
        return true;
    }

    cout << "? Login failed. Invalid username or password.\n";
    return false;
}

#endif

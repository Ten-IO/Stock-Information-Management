#include "search.h"
#include <iostream>
using namespace std;

void displayProduct(const Item& item) {
    cout << "ID: " << item.id << "\n"
         << "Name: " << item.name << "\n"
         << "Category: " << item.category << "\n"
         << "Units: " << item.units << "\n"
         << "Price: " << item.unitPrice << "\n\n";
}

Stock* searchByID(List* ls, int id) {
    Stock* s = ls->head;
    while (s) {
        if (s->item.id == id) return s;
        s = s->next;
    }
    return nullptr;
}

Stock* searchByName(List* ls, const string& name) {
    Stock* s = ls->head;
    while (s) {
        if (s->item.name == name) return s;
        s = s->next;
    }
    return nullptr;
}

vector<Stock*> searchByCategory(List* ls, const string& category) {
    vector<Stock*> results;
    Stock* s = ls->head;
    while (s) {
        if (s->item.category == category) results.push_back(s);
        s = s->next;
    }
    return results;
}

void displaySearchByID(List* ls, int id) {
    Stock* s = searchByID(ls, id);
    if (s) displayProduct(s->item);
    else cout << "ID not found.\n";
}

// Log searches
void searchUsername(Loglist* log, const string& username) {
    Log* node = log->head;
    bool found = false;
    while (node) {
        if (node->user.username == username) {
            cout << "User: " << node->user.username
                 << " | Action: " << node->user.action_type
                 << " | Date: " << node->user.date << "\n";
            found = true;
        }
        node = node->next;
    }
    if (!found) cout << "No logs for user.\n";
}

void searchActionType(Loglist* log, const string& actionType) {
    Log* node = log->head;
    while (node) {
        if (node->user.action_type == actionType)
            cout << "Action: " << node->user.action_type << "\n";
        node = node->next;
    }
}

void searchDate(Loglist* log, const string& date) {
    Log* node = log->head;
    while (node) {
        if (node->user.date == date)
            cout << "Date: " << node->user.date << "\n";
        node = node->next;
    }
}

void searchDateRange(Loglist* log, const string& startDate, const string& endDate) {
    Log* node = log->head;
    while (node) {
        if (node->user.date >= startDate && node->user.date <= endDate)
            cout << "Date: " << node->user.date << "\n";
        node = node->next;
    }
}


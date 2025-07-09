#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "stock.h"
#include "createFile.h" 

using namespace std;

void loadFromCSV(const string& filename, List* ls) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        Item item;
        string token;

        getline(ss, token, ',');
        item.id = stoi(token);
        getline(ss, item.name, ',');
        getline(ss, item.category, ',');
        getline(ss, token, ',');
        item.units = stoi(token);
        getline(ss, token, ',');
        item.unitPrice = stof(token);

        Stock* s = new Stock{item, nullptr};
        if (ls->head == nullptr)
            ls->head = s;
        else
            ls->tail->next = s;
        ls->tail = s;
        ls->n++;
    }

    file.close();
}

void display(List* ls) {
    if (ls == nullptr || ls->head == nullptr) {
        cout << "No items in stock.\n";
        return;
    }

    Stock* s = ls->head;
    while (s != nullptr) {
        cout << s->item.id << " "
             << s->item.name << " "
             << s->item.category << " "
             << s->item.units << " "
             << s->item.unitPrice << "\n";
        s = s->next;
    }
}

void displayFromFile() {
    List* temp = initList();
    loadFromCSV(CURRENT_FILE, temp);
    display(temp);
}

#endif 

#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "stock.h"

using namespace std;


static void createCSV(const string& filename, const vector<string>& header, List* ls) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Can't open file" << endl;
        return;
    }

    for (size_t i = 0; i < header.size(); i++) {
        file << header[i];
        if (i < header.size() - 1)
            file << ",";
    }
    file << "\n";

    if (ls == nullptr || ls->head == nullptr) {
        file.close();
        cout << "File '" << filename << "' created (empty).\n";
        return;
    }

    Stock* current = ls->head;
    while (current != nullptr) {
        file << current->item.id << ",";
        file << current->item.name << ",";
        file << current->item.category << ",";
        file << current->item.units << ",";
        file << current->item.unitPrice << "\n";
        current = current->next;
    }

    file.close();
    cout << "File '" << filename << "' created successfully.\n";
}

#endif // CREATEFILE_H


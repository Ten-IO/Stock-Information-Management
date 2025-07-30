#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "stock.h"
using namespace std;

const string CSV_HEADER[] = {"ID", "Name", "Category", "Unit", "Unit Price"};
const size_t CSV_HEADER_SIZE = sizeof(CSV_HEADER) / sizeof(CSV_HEADER[0]);

static void createCSV(const string& filename, const string header[], size_t headerSize, List* ls, bool append = false) {
    ofstream file;
    if (append)
        file.open(filename, ios::app);
    else
        file.open(filename);

    if (!file.is_open()) {
        cerr << "Can't open file: " << filename << endl;
        return;
    }

    if (!append) {
        for (size_t i = 0; i < headerSize; ++i) {
            file << header[i];
            if (i < headerSize - 1) file << ",";
        }
        file << "\n";
    }

    Stock* current = ls->head;
    while (current != nullptr) {
        file << current->item.id << "," << current->item.name << "," << current->item.category << ","
             << current->item.units << "," << current->item.unitPrice << "\n";
        current = current->next;
    }
    file.close();
}

#endif


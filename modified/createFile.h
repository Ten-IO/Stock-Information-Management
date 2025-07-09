#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "stock.h"
using namespace std;
extern const string CURRENT_FILE = "Current.csv";
extern const string IMPORT_FILE  = "Import.csv";
extern const string EXPORT_FILE  = "Export.csv";
extern const string CSV_HEADER[];
extern const size_t CSV_HEADER_SIZE;

static void createCSV(const string& filename, const string header[], size_t headerSize, List* ls, bool append = false)
{
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
            if (i < headerSize - 1)
                file << ",";
        }
        file << "\n";
    }

    if (ls == nullptr || ls->head == nullptr) {
        file.close();
        //cout << "File '" << filename << "' created (empty).\n";
        return;
    }

    Stock* current = append ? ls->tail : ls->head;
    while (current != nullptr) {
        file << current->item.id << ",";
        file << current->item.name << ",";
        file << current->item.category << ",";
        file << current->item.units << ",";
        file << current->item.unitPrice << "\n";
        if (append) break;
        current = current->next;
    }

    file.close();
}

#endif 

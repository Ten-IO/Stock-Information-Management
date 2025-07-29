#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "stock.h"
#include <ctime>
using namespace std;

extern const string CURRENT_FILE;
//extern const string IMPORT_FILE;
//extern const string EXPORT_FILE;
extern const string LOG_FILE;
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


void getCurrentDateTime(string& dateStr, string& timeStr) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char dateBuf[11], timeBuf[9];
    strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", ltm);
    strftime(timeBuf, sizeof(timeBuf), "%H:%M:%S", ltm);
    dateStr = dateBuf;
    timeStr = timeBuf;
}

bool isFileEmpty(const string& filename) {
    ifstream inFile(filename, ios::binary);
    return inFile.peek() == ifstream::traits_type::eof();
}

void writeLog(int id, const string& name, int qty, const string& user, const string& activity) {
    const std::string LOG_HEADER[] = {"ID", "P.name", "Qty", "Username", "Activity", "Date", "Time"};
    const size_t LOG_HEADER_SIZE = sizeof(LOG_HEADER) / sizeof(LOG_HEADER[0]);

    bool writeHeader = isFileEmpty("log.csv");

    ofstream file("log.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open log.csv\n";
        return;
    }

    if (writeHeader) {
        for (size_t i = 0; i < LOG_HEADER_SIZE; ++i) {
            file << LOG_HEADER[i];
            if (i + 1 < LOG_HEADER_SIZE) file << ",";
        }
        file << "\n";
    }

    string dateStr, timeStr;
    getCurrentDateTime(dateStr, timeStr);

    file << id << "," << name << "," << qty << "," << user << "," << activity << "," << dateStr << "," << timeStr << "\n";
    file.close();
}


#endif 

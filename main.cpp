#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "stock.h"
#include "menu.h"
#include "createFile.h"
#include "fileHeader.h"
using namespace std;

bool fileExists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

int main() {
    if (!fileExists(EXPORT_FILE)) {
        createCSV(EXPORT_FILE, CSV_HEADER, CSV_HEADER_SIZE, nullptr);
    }
    if (!fileExists(IMPORT_FILE)) {
        createCSV(IMPORT_FILE, CSV_HEADER, CSV_HEADER_SIZE, nullptr);
    }

    ofstream f_current(CURRENT_FILE, ios::app); 
    f_current.close();

    menu();
    return 0;
}

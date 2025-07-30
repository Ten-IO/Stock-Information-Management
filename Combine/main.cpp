#include <iostream>
#include "stock.h"
#include "userRole.h"
#include "login.h"
#include "createFile.h"

using namespace std;

int main() {
    List* stocklist = initList();
    Loglist* loglist = initLogList();
    const string CURRENT_FILE = "Current.csv";

    // Initialize CSV
    createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, stocklist, false);

    login(stocklist, loglist, CURRENT_FILE);
    return 0;
}


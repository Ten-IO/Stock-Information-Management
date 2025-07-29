#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "stock.h"
#include "menu.h"
#include "createFile.h"
#include "fileHeader.h"
#include "login.h"
#include "loadCSV.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
bool fileExists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

string currentAdmin = "";
string currentRole = "";


List* stocklist = initList();
void loadCSV(const string& filename, List* list) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        Item item;

        if (!getline(ss, token, ',')) continue;
        item.id = stoi(token);

        if (!getline(ss, token, ',')) continue;
        item.name = token;

        if (!getline(ss, token, ',')) continue;
        item.category = token;

        if (!getline(ss, token, ',')) continue;
        item.units = stoi(token);

        if (!getline(ss, token, ',')) continue;
        item.unitPrice = stod(token);

        addEnd(list, item, false);
    }

    file.close();
}
	
int main() {
	

	loadCSV("Current.csv", stocklist);
    
    ofstream f_current(CURRENT_FILE, ios::app); 
    f_current.close();

    // ? Require admin login before showing menu
    if (!login()) {
        cout << "Access denied. Exiting program...\n";
        return 0;
    }

    // ? If login is successful, continue
    menu();

    return 0;
}


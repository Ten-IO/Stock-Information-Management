#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

#endif


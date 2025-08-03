#include <iostream>
#include <fstream>
#include <Benchmark.h>
#include <sstream>
using namespace std;

int main()
{
    Timer time;
    ifstream ReadFile("product.csv");
    if (!ReadFile.is_open())
    {
        ReadFile.close();
        std::cerr << "File not found";
    }

    string line, blk[5];
    int comma;
    time.flickStart();
    while (getline(ReadFile, line))
    {
        comma = 0;
        for (int i = 0; i < 5; i++)
            blk[i].clear();
        for (char c : line)
        {
            if (c == ',')
            {
                comma++;
                continue;
            }
            if (comma <5)blk[comma]+=c;
        }
        cout << "\n[+] Line: " << line;
        cout << "\n - Item: ";
        for (int i = 0; i < 5; i++)
            cout << blk[i] << " - ";
    }
    time.flickStop();
    time.flickStart();
    ReadFile.clear();
    ReadFile.seekg(0, std::ios::beg);

    while (getline(ReadFile, line, ','))
    line = line;
    time.flickStop();

    ReadFile.clear();
    ReadFile.seekg(0,ios::beg);
    time.flickStart();
    while (getline(ReadFile, line))
{
    int count = 0;
    string current;
    for (char c : line)
    {
        if (c == ',') {
            ++count;
            current.clear();
        } else {
            current += c;
        }
    }
}

    time.flickStop();
}
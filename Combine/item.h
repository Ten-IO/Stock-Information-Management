#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

struct Item {
    int id;
    string name;
    string category;
    int units;
    double unitPrice;
};

#endif


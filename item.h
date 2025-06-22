#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;

struct Item
{
    int id, units;
    string name, category;
    double unitPrice;
};

#endif

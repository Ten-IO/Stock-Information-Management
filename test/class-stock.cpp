#include <iostream>
#include "StockList.h"
int main()
{
    List *ls = new List();
    ls->addItem(Item{1, 100, "NUM1", "", 0.1});
    ls->addItem(Item{1, 100, "NUM2", "", 0.1});
    ls->addItem(Item{1, 100, "NUM3", "", 0.1});
    ls->addItem(Item{1, 100, "NUM4", "", 0.1});
}

void validate(Item item, Item another)
{
    if (item.id == another.id && item.category == another.category && item.name == another.name && item.unitPrice == another.unitPrice && item.units == another.units)
        std::cout << "[+] Sucess!\n";
    else if (item.id == another.id || item.category == another.category || item.name == another.name || item.unitPrice == another.unitPrice || item.units == another.units)
        std::cout << "[-] Problem > 1\n";
    else
        std::cerr << "[!] Error\n";
}

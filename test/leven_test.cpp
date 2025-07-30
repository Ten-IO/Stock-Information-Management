#include <iostream>
#include "Search.h"
#include "StockList.h"
#include "DisplayManager.h"
#include <cassert>

int main()
{
    List *ls = new List;
    ls->addItem(Item{1, 20, "Donut", "Food", 10});
    ls->addItem(Item{1, 20, "Dot", "Food", 10});
    ls->addItem(Item{1, 20, "Cat", "Food", 10});
    ls->addItem(Item{1, 20, "Doat", "Food", 10});
    ls->addItem(Item{1, 20, "Thoat", "Food", 10});
    ls->addItem(Item{1, 20, "Dout", "Food", 10});
    ls->addItem(Item{1, 20, "Dnut", "Food", 10});
    std::cout << "List : \n";
    tableList(ls);

    std::cout << "Search for \'doni\':\n";
    List *res = levenshtein_search("doni", ls, 3);
    std::cout << "List for search : \n";

    tableList(res);

    assert(res->head->item.name == "Donut");
    std::cout << "Approved!\n";
}
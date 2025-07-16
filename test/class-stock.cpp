#include <iostream>
#include "StockList.h"
int main()
{
    List *ls = new List();
    ls->addItem(ls, Item{1, 100, "NUM1", "", 0.1});
    ls->addItem(ls, Item{1, 100, "NUM2", "", 0.1});
    ls->addItem(ls, Item{1, 100, "NUM3", "", 0.1});
    ls->addItem(ls, Item{1, 100, "NUM4", "", 0.1});

    display(ls);
}

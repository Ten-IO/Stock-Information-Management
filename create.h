#include <iostream>
#include "stock.h"

void addEnd(List *ls, Item item)
{
    Stock *s = new Stock;
    s->item = item;
    s->next = nullptr;

    if (ls->head == 0)
        ls->head = s;
    else
        ls->tail->next = s;
    ls->tail = s;
    ls->n++;
}


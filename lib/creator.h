#include <stock.h>

void addEnd(List *ls, Item data)
{
    Stock *s = new Stock;
    s->item = data;
    s->next = nullptr;

    if (ls->head == 0)
        ls->head = s;
    else
        ls->tail->next = s;
    ls->tail = s;
    ls->n++;
}
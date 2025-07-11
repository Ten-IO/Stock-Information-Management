#ifndef CREATOR_H
#define CREATOR_H
#include <stock.h>

/**
 * @brief End-point insertion : similar to vector push_back.
 * @param ls pointer to where item will be added
 * @param data info add to list via Item struct
 * @return void
 */
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

#endif
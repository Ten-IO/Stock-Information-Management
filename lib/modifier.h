#ifndef MODIFIER_H
#define MODIFIER_H

#include <stock.h>
#include <iostream>

/**
 * @brief look for old info via `id` then update
 * @param ls point to list
 * @param oldData not wanted
 * @param newData replace
 * @return void
 */
void modifyViaID(List *, Item, Item);

void modifyViaRatio(List *, Item, Item);

    void modifyViaID(List *ls, Item oldData, Item newData)
{
    Stock *s = ls->head;
    int isFound = 0;
    while (s != nullptr)
    {
        if (s->item.id == oldData.id)
        {
            s->item = newData;
            isFound += 1;
        }
    }
    s = s->next;
    if (isFound != 0)
        std::cout << "data updated\n";
    else
        std::cout << "data unchange\n";
}

#endif
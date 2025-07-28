#include "stock.h"
#include <iostream>

/**
 * @brief look for old info via `id` then update
 * @param List* point to list
 * @param oldData not wanted
 * @param newData replace
 * @return void
 */
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
        std::cout << 
        "data unchange\n";
}

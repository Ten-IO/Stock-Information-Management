#ifndef READER_H
#define READER_H

#include <stock.h>
#include <iostream>

/**
 * @brief extract out of list
 * @param ls point to LinkedList
 * @return void
 */
void display(List *ls)
{
    Stock *s = ls->head;
    while (s != nullptr)
    {
        std::cout << s->item.id << " " << s->item.name << " " << s->item.category << " " << s->item.units << " " << s->item.unitPrice << "\n";
        s = s->next;
    }
}

#endif
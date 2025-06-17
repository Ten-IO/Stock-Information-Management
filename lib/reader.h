#include <stock.h>
#include <iostream>

void display(List *ls)
{
    Stock *s = ls->head;
    while (s != nullptr)
    {
        std::cout << s->item.id << " " << s->item.name << " " << s->item.category << " " << s->item.units << " " << s->item.unitPrice << "\n";
        s = s->next;
    }
}
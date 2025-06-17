#include <stock.h>
#include <iostream>

void deleteAtPos(List *ls, int pos)
{
    if (ls->n == 0 || pos < 0 || pos >= ls->n)
    {
        std::cout << "Invalid pos for stock\n";
        return;
    }
    if (pos == 0)
    {
        Stock *tmp = ls->head;
        ls->head = tmp->next;
        delete tmp;
        if (ls->n == 1)
            ls->tail = nullptr;
    }
    else
    {
        Stock *current = ls->head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        Stock *tmp = current->next;
        current->next = tmp->next;
        if (tmp == ls->tail)
            ls->tail = current;

        delete tmp;
    }
}

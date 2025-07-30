#ifndef DELETE_H
#define DELETE_H

#include "stock.h"

bool delete_id(List* ls, int id) {
    if (ls == nullptr || ls->head == nullptr) return false;

    Stock* current = ls->head;
    Stock* prev = nullptr;

    while (current) {
        if (current->item.id == id) {
            if (prev == nullptr)
                ls->head = current->next;
            else
                prev->next = current->next;
            if (current == ls->tail)
                ls->tail = prev;
            delete current;
            ls->n--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

#endif


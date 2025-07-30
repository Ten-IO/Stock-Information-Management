#ifndef MODIFIER_H
#define MODIFIER_H

#include "stock.h"
#include "createFile.h"

void modifyViaID(List* ls, const Item& oldItem, const Item& newItem) {
    Stock* s = ls->head;
    while (s != nullptr) {
        if (s->item.id == oldItem.id) {
            s->item = newItem;
            break;
        }
        s = s->next;
    }
}
#endif


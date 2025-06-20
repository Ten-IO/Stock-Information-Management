#ifndef ITEM_H
#define ITEM_H
#include <item.h>

struct Stock{
    Item item;
    Stock *next;
};

struct List{
    int n;
    Stock *head;
    Stock *tail;
};

List *initList() {
    List *ls = new List;
    ls->head=nullptr;
    ls->tail=nullptr;
    ls->n=0;
    return ls;
}


#endif
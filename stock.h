#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include "item.h"

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



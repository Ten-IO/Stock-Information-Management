#ifndef ITEM_H
#define ITEM_H
#include <item.h>

/**
 * @struct Item & pointer struct
 * @brief This structure gather Item and address pointer
 * @var item Item data
 * @var next Stock pointer
 */
struct Stock;

/** 
 * @struct Linked List
 * @brief This structure create address head, tail, and put pos
 * @var n position
 * @var head next pointer
 * @var tail previous pointer
 */
struct List;

/**
 * @brief empty list, important first address
 * @return LinkedList : *List
 */
List *initList();

struct Stock
{
    Item item;
    Stock *next;
};

struct List
{
    int n;
    Stock *head;
    Stock *tail;
};

List *initList()
{
    List *ls = new List;
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->n = 0;
    return ls;
}

#endif
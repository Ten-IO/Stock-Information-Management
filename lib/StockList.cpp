#include "StockList.h"

List::List()
{
    initList();
}

List::~List()
{
    Stock *current = head;
    while (current != nullptr)
    {
        Stock *collector = current;
        current = current->next;
        delete collector;
    }
}

void List::initList()
{
    head = nullptr;
    tail = nullptr;
    n = 0;
}

bool List::exist(Item item)
{
    Stock *current = head;
    while (current != nullptr)
    {
        if (current->item.name == item.name)
            return true;
    }
    return false;
}

void List::reverse()
{
    Stock *prev = nullptr, *current = head, *next = nullptr;
    tail = head;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void List::addItem(Item data)
{
    Stock *s = new Stock;
    s->item = data;
    s->next = nullptr;

    if (head == 0)
        head = s;
    else
        tail->next = s;
    tail = s;
    n++;
}

bool List::deleteByPos(int pos)
{
    if (n == 0 || pos < 0 || pos >= n)
        return false;
    if (pos == 0)
    {
        Stock *tmp = head;
        head = tmp->next;
        if (n == 1)
            tail = nullptr;
        n--;
        return true;
    }
    else
    {
        Stock *current = head;
        // get to position
        for (int i = 0; i < pos - 1; i++)
            current = current->next;
        // store 1 next (pos) in temp and delete
        Stock *tmp = current->next;
        current->next = tmp->next;
        // if pos deleted at end, replace
        if (tmp == tail)
            tail = current;
        n--;
        return true;
    }
    return false;
}
bool List::deleteByID(const int &id)
{
    if (head == nullptr)
        return false;
    Stock *current = head;
    Stock *prev = nullptr;

    while (current != nullptr)
    {
        if (current->item.id == id)
        {
            if (prev == nullptr)
            {
                head = current->next;
                if (current == tail)
                    tail = nullptr;
            }
            else
            {
                prev->next = current->next;
                if (current == tail)
                    tail = prev;
            }
            delete current;
            n--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}
bool List::deleteByName(const std::string &name)
{
    if (head == nullptr)
        return false;
    Stock *current = head;
    Stock *prev = nullptr;

    while (current != nullptr)
    {
        if (current->item.name == name)
        {
            if (prev == nullptr)
            {
                head = current->next;
                if (current == tail)
                    tail = nullptr;
            }
            else
            {
                prev->next = current->next;
                if (current == tail)
                    tail = prev;
            }
            delete current;
            n--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

List *List::searchByIDRange(const int a, const int b)
{
    List *tmpList = new List;
    Stock *e = head;
    while (e != nullptr)
    {
        if (e->item.id >= a && e->item.id <= b)
            tmpList->addItem(e->item);
        e = e->next;
    }
    return tmpList;
}
List *List::searchByName(const std::string &name)
{
    List *tmpList = new List;

    Stock *e = head;
    while (e != nullptr)
    {
        if (e->item.name == name)
            tmpList->addItem(e->item);
        e = e->next;
    }
    return tmpList;
}
List *List::searchByCategory(const std::string &category)
{
    List *tmpList = new List;
    Stock *e = head;
    while (e != nullptr)
    {
        if (e->item.category == category)
            tmpList->addItem(e->item);
        e = e->next;
    }
    return tmpList;
}

List *List::searchByUnitRange(int a, int b)
{
    List *tmpList = new List;
    Stock *e = head;
    while (e != nullptr)
    {
        if (e->item.units >= a && e->item.units <= b)
            tmpList->addItem(e->item);

        e = e->next;
    }
    return tmpList;
}
List *List::searchByUnitPriceRange(int a, int b)
{
    List *tmpList = new List;
    Stock *e = head;
    while (e != nullptr)
    {
        if (e->item.unitPrice >= a && e->item.unitPrice <= b)
            tmpList->addItem(e->item);

        e = e->next;
    }
    return tmpList;
}

void List::cleanID()
{
    Stock *current = head;
    int i = 0;
    while (current != nullptr)
    {
        current->item.id = ++i;
        current = current->next;
    }
}
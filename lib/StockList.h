#pragma once
#include "Item.h"

/**
 * @struct Item & pointer struct
 * @brief This structure gather Item and address pointer
 * @var item Item data
 * @var next Stock pointer
 */
struct Stock
{
    Item item;
    Stock *next;
};

/**
 * @class Linked List
 * @brief This structure create address head, tail, and put pos
 */
class List
{
public:
    // position
    int n;
    // next pointer
    Stock *head;
    // tail previous pointer
    Stock *tail;

    List()
    {
        initList();
    }

    ~List()
    {
        Stock *current = head;
        while (current != nullptr)
        {
            Stock *collector = current;
            current = current->next;
            delete collector;
        }
    }

    /**
     * @brief start initalize on first address
     * @return void
     */
    void initList()
    {
        head = nullptr;
        tail = nullptr;
        n = 0;
    }

    /**
     * @brief checking for existing item name
     * @retval true : exist the same name @retval false : does not exist yet
     */
    bool exist(Item item)
    {
        Stock *current = head;
        while (current != nullptr)
        {
            if (current->item.name == item.name)
                return true;
        }
        return false;
    }

    void reverse()
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
    /**
     * @brief End-pointer insertion : similar to vector push_back.
     * @param data add Item to List
     * @return void
     */
    void addItem(Item data)
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

    /**
     * @brief Positional delete, pop out when you get that numerical position.
     * @param pos position on table where you want to dispose
     * @retval `false` invalid position
     * @retval `true` success
     */
    bool deleteByPos(int pos)
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
    }

    bool deleteByID(const int &id)
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
    bool deleteByName(const std::string &name)
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

    /**
     * @brief extract Item out of list with ID
     * @param id product identifier
     * @return void
     */
    List *searchByIDRange(const int &a, const int &b)
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
    List *searchByName(const std::string &name)
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
    List *searchByCategory(const std::string &category)
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

    List *searchByUnitRange(int a, int b)
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
    List *searchByUnitPriceRange(int a, int b)
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

    void cleanID(){
        Stock *current = head;
        int i = 0;
        while(current!=nullptr){
            current->item.id = ++i;
            current = current->next;
        }
    } 
};
#ifndef STOCKLIST_H
#define STOCKLIST_H
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
 * @struct Linked List
 * @brief This structure create address head, tail, and put pos
 * @var n position
 * @var head next pointer
 * @var tail previous pointer
 */
class List
{
public:
    int n;
    Stock *head;
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
     * @brief empty list, important first address
     * @return void
     */
    void initList()
    {
        head = nullptr;
        tail = nullptr;
        n = 0;
    }
    /**
     * @brief End-point insertion : similar to vector push_back.
     * @param ls pointer to where item will be added
     * @param data info add to list via Item struct
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
     * @brief look for old info via `id` then update
     * @param ls point to list
     * @param oldData not wanted
     * @param newData replace
     * @retval `n` amount of changed
     * @retval `-1` not changed
     */
    int modifyViaID(Item oldData, Item newData)
    {
        Stock *s = head;
        int isFound = 0;
        while (s != nullptr)
        {
            if (s->item.id == oldData.id)
            {
                s->item = newData;
                isFound += 1;
            }
        }
        s = s->next;
        if (isFound != 0)
            return -1;
        else
            return isFound;
    }
    /**
     * @brief Positional delete, pop out when you get that numerical position.
     * @param List pointer to where item will be added
     * @param pos numeric point where you want to dispose
     * @retval `-2` invalid position
     * @retval `0` success
     */
    int deleteAtPos(int pos)
    {
        if (n == 0 || pos < 0 || pos >= n)
            return -1;
        if (pos == 0)
        {
            Stock *tmp = head;
            head = tmp->next;
            delete tmp;
            if (n == 1)
                tail = nullptr;
            return 0;
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

            delete tmp;
            return 0;
        }
    }
    /**
     * @brief extract out of list
     * @param ls point to LinkedList
     * @return void
     */
    void showID(int id)
    {
        Stock *s = head;
        while (s != nullptr)
        {
            if (s->item.id == id)
            {
                std::cout << "++ ID: " << s->item.id
                          << " ++ \nName: " << s->item.name
                          << "\nCategory: " << s->item.category
                          << "\nUnits: " << s->item.units
                          << "\nPrice: " << s->item.unitPrice << "\n---------------\n\n";
            }
            s = s->next;
        }
    }
    void showItem(Item item)
    {
        std::cout << "++ ID: " << item.id
                  << " ++ \nName: " << item.name
                  << "\nCategory: " << item.category
                  << "\nUnits: " << item.units
                  << "\nPrice: " << item.unitPrice << "\n---------------\n\n";
    }
    int sortItemID();
};

#endif
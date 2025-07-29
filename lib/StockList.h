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
     * @brief look for info via `id`, then update
     * @param oldData id not wanted
     * @param newData Item to replace
     * @retval `true` changed
     * @retval `false` not changed
     */
    bool modifyViaID(const int &id, Item newData)
    {
        Stock *s = head;
        while (s != nullptr)
        {
            if (s->item.id == id)
            {
                s->item = newData;
                return 1;
            }
            s = s->next;
        }
        delete s;
        return 0;
    }
    /**
     * @brief Positional delete, pop out when you get that numerical position.
     * @param pos position on table where you want to dispose
     * @retval `false` invalid position
     * @retval `true` success
     */
    bool deleteAtPos(int pos)
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
    /**
     * @brief extract Item out of list with ID
     * @param id product identifier
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
                          << " ++\nName: " << s->item.name
                          << "\nCategory: " << s->item.category
                          << "\nUnits: " << s->item.units
                          << "\nPrice: " << s->item.unitPrice << "\n------------------------\n\n";
            }
            s = s->next;
        }
    }

    void showItem()
    {
        Stock *s = head;
        while (s != nullptr)
        {
            std::cout << "   ID: " << s->item.id << " - " << s->item.name << '\n'
                      << "Category: " << s->item.category << '\n'
                      << "unit: " << s->item.units << '\n'
                      << "Price/unit: " << s->item.unitPrice << '\n';
        s=s->next;
        }
    }
    enum class PriceType
    {
        LESS_THAN,
        MORE_THAN
    };
    void showRangePrice(int price, PriceType typeCompare)
    {
    }
};
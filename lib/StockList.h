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
    /**
     * @brief constructor that initialize List using initList()
     * @return empty List
     */
    List();

    /**
     * @brief destructor that is called when object is destroyed
     * @return clean memory for its allocated object
     */
    ~List();

    /**
     * @brief create null address, state size to 0
     * @return empty List
     */
    void initList();

    /**
     * @brief checking for existing item name
     * @retval true : exist the same name @retval false : does not exist yet
     */
    bool exist(Item item);

    /**
     * @brief reverse structure of List from from back to front
     * @return reverse Linked List
     */
    void reverse();

    /**
     * @brief End of List insertion : similar to vector push_back.
     * @param data add Item to List
     * @return void
     */
    void addItem(Item data);

    /**
     * @brief Positional delete, pop out when you get that numerical position.
     * @param pos position on table where you want to dispose
     * @retval `false` invalid position
     * @retval `true` success
     */
    bool deleteByPos(int pos);

    /**
     * @brief id deletion, pop out when correct id is found.
     * @param id id of item to dispose
     * @retval `false` invalid id
     * @retval `true` success
     */
    bool deleteByID(const int &id);

    /**
     * @brief Product name deletion, pop out when product name is found.
     * @param name product name to dispose
     * @retval `false` invalid name
     * @retval `true` success
     */
    bool deleteByName(const std::string &name);

    /**
     * @brief extract Item out of List with ID
     * @param a starting id @param b starting id
     * @return List of found ID range
     */
    List *searchByIDRange(const int a, const int b);

    /**
     * @brief extract Item from List with Product Name
     * @param name product name
     * @return List of found name
     */
    List *searchByName(const std::string &name);

    /**
     * @brief extract Item from List with Category
     * @param category product type/category
     * @return List of found category
     */
    List *searchByCategory(const std::string &category);

    /**
     * @brief extract Item by unit range
     * @param a starting range @param b ending range
     * @return List of found units
     */
    List *searchByUnitRange(int a, int b);

    /**
     * @brief extract Item by price range
     * @param a starting range @param b ending range
     * @return List of found prices
     */
    List *searchByUnitPriceRange(int a, int b);

    /**
     * @brief rearrange id to position
     * @return List with id starting from top to bottom, count as position 1->bottom
     */
    void cleanID();
};

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
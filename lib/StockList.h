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
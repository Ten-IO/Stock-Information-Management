#pragma once
#include <iostream>
#include "StockList.h"

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param ls desired sort list
 * @return array : struct Item
 */
Item *ListToArr(List *, int);

/**
 * @brief factory assister : take static array turn to LinkedList
 * @param arr point to struct Item
 * @param size identified array size
 * @return LinkedList : struct List*
 */
List *ArrToList(Item *, int);

/**
 * @brief divider, comparer, and recontructor for array
 * @param arr array converted from ListToArray()
 * @param left hold start pos
 * @param mid hold medium pos
 * @param right hold end pos
 * @return void - sorting value of divided arrays
 */
void divideMerge(Item[], int, int, int);

/**
 * @brief to merge sort on static arr
 * @param arr point to desired sort Item array
 * @param lb starting point of arrangement
 * @param ub end point of arrangement
 * @return void - combine divided arrays from divideMerge()
 */
void mergeSortArr(Item *, int, int);

/**
 * @brief factory for sort, make changes to LinkedList
 * @param List** ref to pointer of linkedlist
 * @param lb starting point of arrangement
 * @param ub end point of arrangement
 * @return void - combine get Linkedlist by combine divided arrays and convert back
 */
void mergeSortList(List **, int, int);

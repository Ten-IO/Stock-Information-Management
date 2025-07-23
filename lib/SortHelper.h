#ifndef SORTHELPER_H 
#define SORTHELPER_H
#include <iostream>
#include "StockList.h"

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param ls desired sort list
 * @return array : struct Item
 */
Item *ListToArr(List *, int );

/**
 * @brief factory assister : take static array turn to LinkedList
 * @param arr point to struct Item
 * @param size identified array size
 * return LinkedList : struct List*
 */
List *ArrToList(Item *, int );

/**
 * @brief divider, comparer, and recontructor for array
 * @param arr array converted from ListToArray()
 * @param left hold start pos
 * @param mid hold medium pos
 * @param right hold end pos
 * @return void
 */
void divideMerge(Item[] , int , int , int );

/**
 * @brief use merge sort on static arr
 * @param arr point to desired sort Item array
 * @param pos1 starting point of arrangement
 * @param ub end point of arrangement
 * @return void
 */
void mergeSortArr(Item*, int , int );

/**
 * @brief factory for sort, make changes to LinkedList
 * @param List* point linkedlist
 * @param pos1 starting point of arrangement
 * @param ub end point of arrangement
 * @return void
 */
void mergeSortList(List **ls, int pos1, int ub);

Item *ListToArr(List *ls, int size)
{
    Item *arr = new Item[size];
    if (size == 0)
        return nullptr;
    Stock *current = ls->head;
    for (int i = 0; i < size && current != nullptr; i++)
    {
        arr[i] = current->item;
        current = current->next;
    }
    return arr;
}

List *ArrToList(Item *arr, int size)
{
    List *ls = new List();
    for (int i = 0; i < size; i++)
        ls->addItem(arr[i]);

    return ls;
}

void divideMerge(Item arr[], int left, int mid, int right)
{
    int lb = mid - left + 1, ub = right - mid;

    Item *leftSide = new Item[lb], *rightSide = new Item[ub];

    for (int i = 0; i < lb; i++)
        leftSide[i] = arr[left + i];
    for (int j = 0; j < ub; j++)
        rightSide[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < lb && j < ub)
    {
        if (leftSide[i].id <= rightSide[j].id)
        {
            arr[k] = leftSide[i];
            i++;
        }
        else
        {
            arr[k] = rightSide[j];
            j++;
        }
        k++;
    }
    while (i < lb)
    {
        arr[k] = leftSide[i];
        i++;
        k++;
    }
    while (j < ub)
    {
        arr[k] = rightSide[j];
        j++;
        k++;
    }
    delete[] leftSide;
    delete[] rightSide;
}

void mergeSortArr(Item *arr, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        mergeSortArr(arr, lb, mid);
        mergeSortArr(arr, mid + 1, ub);
        divideMerge(arr, lb, mid, ub);
    }
}

void mergeSortList(List **ls, int lb, int ub)
{
    int size = (*ls)->n;
    Item *arr;

    arr = ListToArr(*ls, size);

    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        mergeSortArr(arr, lb, mid);
        mergeSortArr(arr, mid + 1, ub);
        divideMerge(arr, lb, mid, ub);
    }
    *ls = ArrToList(arr, size);
    delete[] arr;
}

#endif

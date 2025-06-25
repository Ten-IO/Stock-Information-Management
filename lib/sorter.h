#ifndef STOCK_H
#define STOCK_H
#include <creator.h>
#include <new>
#include <iostream>
#include <reader.h>

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param List* desired sort list
 * @return array:Stock
 */
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
    List *ls = initList();
    for (int i = 0; i < size; i++)
        addEnd(ls, arr[i]);

    return ls;
}

/**
 * @brief divider, comparer, and recontructor for array
 * @param Stock array converted from ListToArray()
 * @param left hold start pos
 * @param mid hold medium pos
 * @param right hold end pos
 * @return void
 */
void divideMerge(Item arr[], int left, int mid, int right)
{
    int par1 = mid - left + 1, par2 = right - mid;

    Item *leftSide = new Item[par1], *rightSide = new Item[par2];

    for (int i = 0; i < par1; i++)
        leftSide[i] = arr[left + i];
    for (int j = 0; j < par2; j++)
        rightSide[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < par1 && j < par2)
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
    while (i < par1)
    {
        arr[k] = leftSide[i];
        i++;
        k++;
    }
    while (j < par2)
    {
        arr[k] = rightSide[j];
        j++;
        k++;
    }
    delete[] leftSide;
    delete[] rightSide;
}

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param List* desired sort list
 * @return array:Stock
 */
void mergeSortArr(Item *arr, int pos1, int pos2)
{
    if (pos1 < pos2)
    {
        int mid = pos1 + (pos2 - pos1) / 2;

        mergeSortArr(arr, pos1, mid);
        mergeSortArr(arr, mid + 1, pos2);

        divideMerge(arr, pos1, mid, pos2);
    }
}

/**
 * @brief factory for sort, make changes to LinkedList
 * @param List* point linkedlist
 * @param pos1 starting point of arrangement
 * @param pos2 end point of arrangement
 * @return void
 */
void mergeSortList(List **ls, int pos1, int pos2)
{

    int size = (*ls)->n;
    Item *arr;

    arr = ListToArr(*ls, size);

    if (pos1 < pos2)
    {
        int mid = pos1 + (pos2 - pos1) / 2;

        mergeSortArr(arr, pos1, mid);
        mergeSortArr(arr, mid + 1, pos2);

        divideMerge(arr, pos1, mid, pos2);
    }
    *ls = ArrToList(arr, size);
    delete[] arr;
}

#endif
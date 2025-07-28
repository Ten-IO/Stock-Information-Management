#include <new>
#include <iostream>
#include "stock.h"
#include "userRole.h"

enum SortField { By_ID, By_Name, By_Unit, By_UnitPrice};
enum SortOrder { ASCENDING, DESCENDING };

// enum LogSortField {
//     By_Username,
//     By_Date
// };

bool compareItems( const Item& a, const Item& b , SortField field, SortOrder order){
    bool result = true;
    switch(field){
        case By_ID: {
            result = (a.id <= b.id);
            break;
        } 
        case By_Name: {
            result = (a.name <= b.name);
            break;
        }
        case By_Unit: {
            result = (a.units <= b.units);
            break;
        }
        case By_UnitPrice: {
            result = (a.unitPrice <= b.unitPrice);
            break;
        }
    }
    return (order == ASCENDING) ?  result : !result;
}
// bool compareItemsLog( const User& a, const User& b , LogSortField Logfield, SortOrder order){
//     bool result = true;
//     switch(Logfield){
//         case By_Username: {
//             result = (a.username <= b.username);
//             break;
//         } 
//         case By_Date: {
//             result = (a.date <= b.date);
//             break;
//         }
//     }
//     return (order == ASCENDING) ?  result : !result;
// }
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
// Item *LogListToArr(Loglist *log, int size)
// {
//     Item *arr = new Item[size];
//     if (size == 0)
//         return nullptr;
//     Log *current = log->head;
//     for (int i = 0; i < size && current != nullptr; i++)
//     {
//         arr[i] = current -> user;
//         current = current->next;
//     }
//     return arr;
// }

List *ArrToList(Item *arr, int size)
{
    List *ls = initList();
    for (int i = 0; i < size; i++)
        addEnd(ls, arr[i]);

    return ls;
}
// List * LogArrToList(Item *arr, int size)
// {
//     Loglist *log = initLogList();
//     for (int i = 0; i < size; i++)
//         addEndLog(log, arr[i]);

//     return log;
// }
/**
 * @brief divider, comparer, and recontructor for array
 * @param Stock array converted from ListToArray()
 * @param left hold start pos
 * @param mid hold medium pos
 * @param right hold end pos
 * @param field hold which field was chosen
 * @param order hold which order was chosen
 * @return void
 */
void divideMerge(Stock arr[], int left, int mid, int right,SortField field, SortOrder order );
void divideMerge(Item arr[], int left, int mid, int right, SortField field, SortOrder order)
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
        if (compareItems(leftSide[i], rightSide[j], field, order))
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
// void divideMergeLog(Item arr[], int left, int mid, int right, LogSortField Logfield, SortOrder order)
// {
//     int par1 = mid - left + 1, par2 = right - mid;

//     Item *leftSide = new Item[par1], *rightSide = new Item[par2];

//     for (int i = 0; i < par1; i++)
//         leftSide[i] = arr[left + i];
//     for (int j = 0; j < par2; j++)
//         rightSide[j] = arr[mid + 1 + j];
//     int i = 0, j = 0, k = left;
//     while (i < par1 && j < par2)
//     {
//         if (compareItemsLog(leftSide[i], rightSide[j], Logfield, order))
//         {
//             arr[k] = leftSide[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = rightSide[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < par1)
//     {
//         arr[k] = leftSide[i];
//         i++;
//         k++;
//     }
//     while (j < par2)
//     {
//         arr[k] = rightSide[j];
//         j++;
//         k++;
//     }
//     delete[] leftSide;
//     delete[] rightSide;
// }
/**
 * @brief factory for sort, make changes to LinkedList
 * @param List* point linkedlist
 * @param pos1 starting point of arrangement
 * @param pos2 end point of arrangement
 * @return void
 */
// void mergeSort(List *ls, int pos1, int pos2)
// {
//     Stock *arr = ListToArr(ls);
//     if (pos1 < pos2)
//     {
//         int mid = pos1 + (pos2 - pos1) / 2;

//         mergeSort(arr, pos1, mid);
//         mergeSort(arr, mid + 1, pos2);

//         divideMerge(arr, pos1, mid, pos2);
//     }
// }

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param List* desired sort list
 * @return array:Stock
 */
void mergeSort(Stock *arr, int pos1, int pos2, SortField field, SortOrder order);
void mergeSortArr(Item *arr, int pos1, int pos2, SortField field, SortOrder order)
{
    if (pos1 < pos2)
    {
        int mid = pos1 + (pos2 - pos1) / 2;

        mergeSortArr(arr, pos1, mid, field, order);
        mergeSortArr(arr, mid + 1, pos2, field, order);
        divideMerge(arr, pos1, mid, pos2, field, order);
    }
}
// void mergeSortArrLog(Item *arr, int pos1, int pos2, LogSortField Logfield, SortOrder order)
// {
//     if (pos1 < pos2)
//     {
//         int mid = pos1 + (pos2 - pos1) / 2;

//         mergeSortArrLog(arr, pos1, mid, Logfield, order);
//         mergeSortArrLog(arr, mid + 1, pos2, Logfield, order);
//         divideMergeLog(arr, pos1, mid, pos2, Logfield, order);
//     }
// }
// void divideMerge(Item arr[], int left, int mid, int right)
// {
//     int par1 = mid - left + 1, par2 = right - mid;

//     Item *leftSide = new Item[par1], *rightSide = new Item[par2];

//     for (int i = 0; i < par1; i++)
//         leftSide[i] = arr[left + i];
//     for (int j = 0; j < par2; j++)
//         rightSide[j] = arr[mid + 1 + j];
//     int i = 0, j = 0, k = left;
//     while (i < par1 && j < par2)
//     {
//         if (leftSide[i].id <= rightSide[j].id)
//         {
//             arr[k] = leftSide[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = rightSide[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < par1)
//     {
//         arr[k] = leftSide[i];
//         i++;
//         k++;
//     }
//     while (j < par2)
//     {
//         arr[k] = rightSide[j];
//         j++;
//         k++;
//     }
//     delete[] leftSide;
//     delete[] rightSide;
// }
// void mergeSortArr(Item *arr, int pos1, int pos2)
// {
//     if (pos1 < pos2)
//     {
//         int mid = pos1 + (pos2 - pos1) / 2;

//         mergeSortArr(arr, pos1, mid);
//         mergeSortArr(arr, mid + 1, pos2);

//         divideMerge(arr, pos1, mid, pos2);
//     }
// }

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param List* desired sort list
 * @return array:Stock
 */

Stock *ListToArr(List *ls)
/**
 * @brief factory for sort, make changes to LinkedList
 * @param List* point linkedlist
 * @param pos1 starting point of arrangement
 * @param pos2 end point of arrangement
 * @return void
 */
// void mergeSortList(List **ls, int pos1, int pos2)
// {

//     int size = (*ls)->n;
//     Item *arr;

//     arr = ListToArr(*ls, size);

//     if (pos1 < pos2)
//     {
//         int mid = pos1 + (pos2 - pos1) / 2;

//         mergeSortArr(arr, pos1, mid);
//         mergeSortArr(arr, mid + 1, pos2);

//         divideMerge(arr, pos1, mid, pos2);
//     }
//     return arr;
// }
// Stock *ArrToList(List *ls){
//     *ls = ArrToList(arr, size);
//     delete[] arr;
// }



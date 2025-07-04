#include <stock.h>

/**
 * @brief divider, comparer, and recontructor for array
 * @param Stock array converted from ListToArray()
 * @param left hold start pos
 * @param mid hold medium pos
 * @param right hold end pos
 * @return void
 */
void divideMerge(Stock arr[], int left, int mid, int right)
{
    int i, j, k;
    int par1 = mid - left + 1, par2 = right - mid;

    Stock *leftSide = new Stock[par1], *rightSide = new Stock[par2];

    for (i = 0; i < par1; i++)
        leftSide[i] = arr[left + i];
    for (j = 0; j < par2; j++)
        rightSide[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < par1 && j < par2)
    {
        if (leftSide[i].item.id <= rightSide[i].item.id)
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
    delete []rightSide;
}

/**
 * @brief factory for sort, make changes to LinkedList
 * @param List* point linkedlist
 * @param pos1 starting point of arrangement
 * @param pos2 end point of arrangement
 * @return void
 */
void mergeSort(List *ls, int pos1, int pos2)
{
    Stock *arr = ListToArr(ls);
    if (pos1 < pos2)
    {
        int mid = pos1 + (pos2 - pos1) / 2;

        mergeSort(arr, pos1, mid);
        mergeSort(arr, mid + 1, pos2);

        divideMerge(arr, pos1, mid, pos2);
    }
}

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param List* desired sort list
 * @return array:Stock
 */
void mergeSort(Stock *arr, int pos1, int pos2)
{
    if (pos1 < pos2)
    {
        int mid = pos1 + (pos2 - pos1) / 2;

        mergeSort(arr, pos1, mid);
        mergeSort(arr, mid + 1, pos2);

        divideMerge(arr, pos1, mid, pos2);
    }
}

/**
 * @brief factory assister : turn array to static for quicker sort
 * @param List* desired sort list
 * @return array:Stock
 */
Stock *ListToArr(List *ls)
{
    int max = ls->n;
    Stock *arr = new Stock[max];
    if (max == 0)
        return;
    Stock *current = ls->head;
    for (int i = 0; i < max && current != nullptr; i++)
    {
        arr[i].item = current->item;
        current = current->next;
    }
    return arr;
}

Stock *ArrToList(List *ls){}
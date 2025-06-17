#include <stock.h>

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
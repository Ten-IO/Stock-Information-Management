#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include "stock.h"

enum SortField { By_ID, By_Name, By_Unit, By_UnitPrice };
enum SortOrder { ASCENDING, DESCENDING };

bool compareItems(const Item& a, const Item& b, SortField field, SortOrder order) {
    bool result;
    switch (field) {
        case By_ID: result = a.id <= b.id; break;
        case By_Name: result = a.name <= b.name; break;
        case By_Unit: result = a.units <= b.units; break;
        case By_UnitPrice: result = a.unitPrice <= b.unitPrice; break;
    }
    return (order == ASCENDING) ? result : !result;
}

Item* ListToArr(List* ls, int size) {
    if (size == 0) return nullptr;
    Item* arr = new Item[size];
    Stock* cur = ls->head;
    for (int i = 0; i < size && cur; i++) {
        arr[i] = cur->item;
        cur = cur->next;
    }
    return arr;
}

List* ArrToList(Item* arr, int size) {
    List* ls = initList();
    for (int i = 0; i < size; i++) {
        Stock* node = new Stock{arr[i], nullptr};
        if (!ls->head)
            ls->head = ls->tail = node;
        else {
            ls->tail->next = node;
            ls->tail = node;
        }
        ls->n++;
    }
    return ls;
}

void merge(Item arr[], int left, int mid, int right, SortField field, SortOrder order) {
    int n1 = mid - left + 1, n2 = right - mid;
    Item* L = new Item[n1];
    Item* R = new Item[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareItems(L[i], R[j], field, order))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSortArr(Item arr[], int left, int right, SortField field, SortOrder order) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortArr(arr, left, mid, field, order);
        mergeSortArr(arr, mid + 1, right, field, order);
        merge(arr, left, mid, right, field, order);
    }
}

#endif


#include "Sort.h"
#include <stdlib.H>
#include <time.h>
#include <stdio.h>

void Sort::InsertSort(bool ascendent)
{

    for (int i = 1; i < GetElementsCount(); ++i) {
        int key = this->list[i];
        int j = i - 1;

   
        if (ascendent) {
            while (j >= 0 && this->list[j] > key) {
                this->list[j + 1] = this->list[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && this->list[j] < key) {
                this->list[j + 1] = this->list[j];
                j = j - 1;
            }
        }
        this->list[j + 1] = key;
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, bool ascendent) {
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if ((ascendent && arr[j] <= pivot) || (!ascendent && arr[j] >= pivot)) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, bool ascendent) {
    if (low < high) {
        int pi = partition(arr, low, high, ascendent);

        quickSort(arr, low, pi - 1, ascendent);
        quickSort(arr, pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    quickSort(this->list, 0, GetElementsCount() - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int len = GetElementsCount();
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (ascendent) {
                if (this->list[i] > this->list[j])
                {
                    int p;
                    p = this->list[i];
                    this->list[i] = this->list[j];
                    this->list[j] = p;
                }
            }
            else
            {
                if (this->list[i] < this->list[j])
                {
                    int p;
                    p = this->list[i];
                    this->list[i] = this->list[j];
                    this->list[j] = p;
                }
            }
        }
    }
    ascendent = true;
}

void Sort::Print()
{
    int len = GetElementsCount();
    for (int i = 0; i < len; i++)
    {
        printf("%d ", this->list[i]);
    }
}

int  Sort::GetElementsCount()
{
    return this->nr;
}

int  Sort::GetElementFromIndex(int index)
{
    return this->list[index];
}

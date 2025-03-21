#pragma once
#include <stdlib.H>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>

class Sort
{
    int* list;
    int nr;
public:
    Sort(int count, int min, int max)//random values
    {
        list = new int[count];
        time_t t;
        srand((unsigned)time(&t));
        for (int i = 0; i < count; i++)
        {
            list[i] = min + rand() % (max - min + 1);
        }
        nr = count;
    };

    Sort(int count, int vector[])//existing vector
    {
        list = new int[count];
        for (int i = 0; i < count; i++)
            list[i] = vector[i];
        nr = count;

    };

    Sort(int count ...)//variadric
    {
        list = new int[count];
        va_list vl;
        va_start(vl, count);
        for (int i = 0; i < count; i++)
            list[i] = va_arg(vl, int);
        va_end(vl);
        nr = count;
    };

    Sort(char string[])//string
    {
        int i=0,j=0;
        list = new int[50];
        list[0] = 0;
        while (string[i] != '\0')
        {
            if (string[i] == ',')
            {
                j++;
                list[j] = 0;
                i++;
            }
            else
                list[j] = 10 * list[j] + string[i++] - '0';            
        }
        nr = j;
    };

    Sort() : list(new int[6] {1, 2, 3, 4, 5, 6}) { nr = 6; };

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};



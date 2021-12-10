/*******************************************************/
/** Sắp xếp sinh viên theo loại thông tin và thuật toán*/
/*******************************************************/
#pragma once
#include "condition.h"

// be hon  : 1
// lon hon : -1
// bang nhau : 0

void selection_sort(string key, Student_list &List)
{
    int indexMin, i, j, n = List.getN(); // min là chỉ số phần tử nhỏ nhất
    for (i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (j = i + 1; j < n; j++)
            if (compare(key, List.at(j), List.at(indexMin)) == -1) // a[j] < a[indexMin])
                indexMin = j;                                      // tìm min trong các phần tử còn lại

        if (indexMin != i)
            List.swap(List.at(i), List.at(indexMin)); //đổi chỗ nếu tìm thấy min
    }
}

void insertion_sort(string key, Student_list &List)
{
    int i, j, n = List.getN();
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j >= 0 && compare(key, List.at(j), List.at(j - 1)) == -1)
        {
            List.swap((List.at(j - 1)), (List.at(j)));
            j = j - 1;
        }
    }
}

void quick_sort(string key, Student_list &List, int l, int r)
{
    if (l <= r)
    {
        Student *st = List.at((l + r) / 2);
        int i = l;
        int j = r;

        while (i <= j)
        {
            while (compare(key, List.at(i), st) == -1 && i < r) // == -1 : be hon
                i++;
            while (compare(key, List.at(j), st) == 1 && j > l) // == 1 : lon hon
                j--;
            if (i <= j)
            {
                List.swap(List.at(i), List.at(j));
                i++;
                j--;
            }
        }

        if (l < j)
            quick_sort(key, List, l, j);
        if (r > i)
            quick_sort(key, List, i, r);
    }
    
}

void bubble_sort(string key, Student_list &List)
{
    int n = List.getN();
    for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
           if (compare(key,List.at(j),List.at(j+1)) == 1) 
		        List.swap(List.at(j), List.at(j+1));
}

void Sort(string key, string algorithm, Student_list &List)
{
    if (algorithm == "QuickSort")
        quick_sort(key, List, 0, List.getN() - 1);
    if (algorithm == "SelectionSort")
        selection_sort(key, List);
    if (algorithm == "InsertionSort")
        insertion_sort(key, List);
    if (algorithm == "BubbleSort")
        bubble_sort(key, List);
}



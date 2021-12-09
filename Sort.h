/*******************************************************/
/** Sắp xếp sinh viên theo loại thông tin và thuật toán*/
/*******************************************************/

#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

// typedef vector<Student> student_list;

// be hon  : 1
// lon hon : -1
// bang nhau : 0


int compare_birthday(Student *st1, Student *st2)
{
    if (st1->getYear() > st2->getYear())
        return -1;
    if (st1->getYear() < st2->getYear())
        return 1;

    if (st1->getMonth() > st2->getMonth())
        return -1;
    if (st1->getMonth() < st2->getMonth())
        return 1;

    if (st1->getDay() > st2->getDay())
        return -1;
    if (st1->getDay() < st2->getDay())
        return 1;

    // if(st1->getDate() > st2->getDate()){
    //     return -1;
    // }
    // ngay sinh giong nhau
    return 0;
}

int compare_name(Student *st1, Student *st2)
{ // so sanh hai ten
    /*Lay last name ***************/
    char *name1, *name2;
    name1 = st1->getname();
    name2 = st2->getname();
    char lname1[20], lname2[20];
    for (int i = strlen(name1) - 1; i >= 0; i--)
    {
        if (name1[i] == ' ')
        {
            strcpy(lname1, name1 + 1 + i);
            break;
        }
    }
    // cout << "Last Name 1: " << lname1 << endl;
    for (int i = strlen(name2) - 1; i >= 0; i--)
    {
        if (name2[i] == ' ')
        {
            strcpy(lname2, name2 + 1 + i);
            break;
        }
    }
    // cout << "Last Name 2: " << lname2 << endl;

    /*So sanh hai last name **************/
    int check = strcmpi(lname1, lname2);
    // cout << "Check = " << check << endl;
    if (check > 0)
        return 1;
    if (check < 0)
        return -1;
    /*Neu hai last name trung nhau thi so sanh ho */
    if (check == 0) // hai ten trung nhau
    {
        check = strcmpi(name1, name2);
        if (check > 0)
            return 1;
        if (check < 0)
            return -1;
    }
    return 0;
}


int compare(string key, Student *st1, Student *st2)
{
    int x = 0;
    if (key == "AveragePoint")
        x = 1;
    if (key == "StudentCode")
        x = 2;
    if (key == "ClassName")
        x = 3;
    if (key == "Name")
        x = 4;
    if (key == "Birthday")
        x = 5;

    switch (x)
    {
    case 1: // the0 diem trung binh
        if (st1->getDiemTb() > st2->getDiemTb())
            return -1;
        if (st1->getDiemTb() < st2->getDiemTb())
            return 1;
        else
            return 0;

    case 2: // theo ma sinh vien
        if (strcmpi(st1->getstudentCode(), st2->getstudentCode()) > 0)
            return 1;
        else
            return -1;
        return 0; // khong co chuyen ma sv bang nhau

    case 3: // theo ten lop
        if (strcmpi(st1->getclassName(), st2->getclassName()) > 0)
            return 1;
        if (strcmpi(st1->getclassName(), st2->getclassName()) < 0)
            return -1;
        // Cung ma lop sap xep theo ho ten
        if (compare_name(st1, st2) != 0)
            return compare_name(st1, st2);
        // cung ho ten sap theo ngay sinh
        else
            return compare_birthday(st1, st2);

    case 4: // theo ten sinh vien
        if (compare_name(st1, st2) != 0)
            return compare_name(st1, st2);
        else
            return compare_birthday(st1, st2); // cung ho ten so sanh ngay sinh

    case 5: // theo ngay sinh
        return compare_birthday(st1, st2);
    }
    return 0;
}

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



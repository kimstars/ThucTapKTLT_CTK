#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

//So sánh hai ngày sinh
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

//So sánh hai tên
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

//So sánh cho sắp xếp
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
        return 0;

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

        return 0;

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

// so sánh bằng nhau cho tìm kiếm
int compareBST(string key, Student *st1, Student *st2)
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
    case 1: //
        if (st1->getDiemTb() == st2->getDiemTb())
            return 1;
        else
            return 0;

    case 2: // theo ma sinh vien

        if (strInStr(st1->getstudentCode(), st2->getstudentCode()) >= 0)
            return 1;
        return 0;

    case 3: // theo ten lop
        if (strInStr(st1->getclassName(), st2->getclassName()) >= 0)
            return 1;
        return 0;

    case 4: // theo ten sinh vien
        if (strInStr(st1->getname(), st2->getname()) >= 0)
            return 1;
        return 0;

    case 5: // theo ngay sinh
        Date item = st1->getDate();
        Date item1 = st2->getDate();

        if (item1.year == item.year || item1.month == item.month || item1.day == item.day)
        {
            return 1;
        }
        return 0;
    }
    return 0;
}
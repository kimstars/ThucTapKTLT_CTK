#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include "helper.h"
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
    void operator=(const Date d)
    {
        day = d.day;
        month = d.month;
        year = d.year;
    }
    friend istream &operator>>(istream &is, Date &d);
    bool operator>(const Date &d)
    {
        if (year < d.year)
        {
            return 1;
        }
        if (month < d.month)
        {
            return 1;
        }
        if (day < d.day)
        {
            return 1;
        }
        return 0;
    }

    bool operator==(const Date &d)
    {
        if (year == d.year && month == d.month && day == d.day)
        {
            return 1;
        }
        return 0;
    }

    


};

istream &operator>>(istream &is, Date &d)
{
    is >> d.day >> d.month >> d.year;
    while (is.fail())
    {
        cout << "Vui long nhap ngay thang nam la so nguyen. ";
        is.clear();
        is.ignore(256, '\n');
        cout << "(dd/mm/yyyy)\n";
        is >> d.day >> d.month >> d.year;
    }
    return is;
}

#ifndef student
#define student
class Student{
private:
    char name[30];
    char studentCode[30];
    char className[30];
    Date birthday;
    double diemtb;

public:
    Student *next;

    Student()
    {
        strcpy(name, "");
        strcpy(className, "");
        strcpy(studentCode, "");

        birthday.day = birthday.month = birthday.year = 0;
        diemtb = 0;
        next = NULL;
    }

    Student(char *tenlop, char *maSV, char *hoten, int ngay, int thang, int nam, double tb)
    {
        strcpy(className, tenlop);
        strcpy(studentCode, maSV);
        strcpy(name, hoten);
        birthday.day = ngay;
        birthday.month = thang;
        birthday.year = nam;
        diemtb = tb;
    }
    ~Student(){};

    friend ostream &operator<<(ostream &os, Student);
    friend istream &operator>>(istream &os, Student &);
    void operator=(const Student &s)
    {
        strcpy(name, s.name);
        // name = s.name;
        strcpy(className, s.className);
        strcpy(studentCode, s.studentCode);
        birthday = s.birthday;
        diemtb = s.diemtb;
    }


    int getDay() { return birthday.day; }
    int getMonth() { return birthday.month; }
    int getYear() { return birthday.year; }
    double getDiemTb() { return diemtb; }
    Date getDate() { return birthday; }

    get_func(char *, className);
    get_func(char *, studentCode);
    get_func(char *, name);
    get_func(Date, birthday);
    get_func(double, diemtb);

    set_func(Date, birthday);
    set_func(double, diemtb);
    
    void setname(char *name) {strcpy(this->name, name);}
    void setstudentCode(char *studentCode) {strcpy(this->studentCode, studentCode);}
    void setclassName(char *className) {strcpy(this->className, className);}

    char *ToUpper(char *a);
    char *chuanhoaten(char *a);
    void chuanhoa();

    bool checkMaSV(char *code);


};

ostream &operator<<(ostream &os, Student s)
{
    os << "Ma sinh vien :" << setw(15) << s.studentCode << " | Ten : " << setw(20) << s.name << " | Ma lop :" << setw(10) << s.className
       << " | Ngay sinh : " << s.birthday.day << "/" << s.birthday.month << "/" << s.birthday.year
       << " | Diem tb: " << s.diemtb << endl;
    return os;
}
// Chuyen thanh in hoa het
char *Student::ToUpper(char *a)
{
    // chuyen thanh chu hoa het
    strcpy(a, strupr(a));
    // bo dau cach thua dau xau;
    int i = 0;
    while (a[i] == ' ' && i < strlen(a))
        i++;
    strcpy(&a[0], &a[i]);
    // bo dau cach thua o giua xau
    i = 0;
    while (i < strlen(a) - 1)
    {
        if (a[i] == ' ' && a[i + 1] == ' ')
            strcpy(&a[i], &a[i + 1]);
        else
            i++;
    }
    // bo dau cach thua o cuoi xau
    while (a[strlen(a)] == ' ')
        a[strlen(a)] = '\0';
    return a;
}

char *Student::chuanhoaten(char *a)
{
    // chuyen thanh chu thuong het
    strcpy(a, strlwr(a));
    // bo dau cach thua dau xau;
    int i = 0;
    while (a[i] == ' ' && i < strlen(a))
        i++;
    strcpy(&a[0], &a[i]);
    // bo dau cach thua o giua xau
    i = 0;
    while (i < strlen(a) - 1)
    {
        if (a[i] == ' ' && a[i + 1] == ' ')
            strcpy(&a[i], &a[i + 1]);
        else
            i++;
    }
    // bo dau cach thua o cuoi xau
    while (a[strlen(a)] == ' ')
        a[strlen(a)] = '\0';

    // Viet hoa cac tu dau
    int n = strlen(a);
    if (a[0] != 32)
    {
        if (a[0] > 96 && a[0] < 123)
        {
            a[0] -= 32;
        }
    }
    for (i = 1; i < n; i++)
    {
        if (a[i] == 32)
        {
            if (a[i + 1] > 96 && a[i + 1] < 123)
            {
                a[i + 1] -= 32;
            }
        }
    }
    return a;
}

void Student::chuanhoa()
{
    strcpy(className, ToUpper(className));
    strcpy(name, chuanhoaten(name));
}

bool Student::checkMaSV(char *code)
{
    if (strcmp(code, studentCode) > 0)
    {
        return 1;
    }
    return 0;
}



#define get_func(type, object)

#endif

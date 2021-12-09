#pragma once 
#include <iostream>
#include <vector>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "Student.h"
#include "rlutil.h"
#include "Input.h"
#include "BieuDo.h"


using namespace std;

int strInStr(char *kidStr, char *papaStr)
{
    char *tmp;
    if (tmp = strstr(papaStr, kidStr))
    {
        return (tmp - papaStr);
    }
    else
    {
        return -1;
    }
}

// chuyen thanh chu thuong het
char *toLower(char *a)
{
    for (int i = 0; i <= strlen(a); i++)
    {
        if (a[i] >= 65 && a[i] <= 92)
        {
            a[i] = a[i] + 32;
        }
    }
    return a;
}

void toChar(string str, char value[30])
{
    int length = str.length();
    for (int i = 0; i < length; i++)
        value[i] = str[i];
    value[length] = '\0';
}

void toString(string &str, char value[30])
{
    str = "";
    for (int i = 0; i < strlen(value); i++)
        str = str + value[i];
}



typedef LinkedList Student_list;
void Search(string type, string keyword, string accuracy, Student_list List)
{
    Student_list ListExactly;
    Student_list ListNearly;
    ListExactly.clear();
    ListNearly.clear();
    char cKeyword[40];
    toChar(keyword, cKeyword);
    strcpy(cKeyword, touper(cKeyword));
    // cout << "kiet : "<<cKeyword;
    int Size = List.getN();

    if (type == "Name")
    {

        for (int i = 0; i < Size; i++)
        {
            char name[40];
            strcpy(name, List.at(i)->getname()); //->copy to new char[]
            // cout << name << "|" ;
            touper(name);
            // cout << name << endl;
            if (strcmp(cKeyword, name) == 0)
            {
                // cout << "kiet check : \n"<< List[i] <<endl;
                ListExactly.push_back(List[i]);
                // cout << "ok1";
                ListNearly.push_back(List[i]);
            }
            else if (strInStr(cKeyword, name) >= 0 || strInStr(name, cKeyword) >= 0)
            {
                ListNearly.push_back(List[i]);

            }
            cout << i << "";
        }
    }
    else if (type == "ClassName")
    {
        for (int i = 0; i < Size; i++)
        {
            char className[30];
            strcpy(className, List.at(i)->getclassName()); //->copy to new char[]
            touper(className);
            if (strcmp(cKeyword, className) == 0)
            {
                ListExactly.push_back(List[i]);
                ListNearly.push_back(List[i]);
            }
            else if (strInStr(cKeyword, className) >= 0 || strInStr(className, cKeyword) >= 0)
            {
                ListNearly.push_back(List[i]);
                
            }
        }
        cout << ListExactly.getN();
    }
    else if (type == "StudentCode")
    {
        for (int i = 0; i < Size; i++)
        {
            char id[30];
            strcpy(id, List.at(i)->getstudentCode()); //->copy to new char[]
            touper(id);
            if (strcmp(cKeyword, id) == 0)
            {
                ListExactly.push_back(List[i]);
                ListNearly.push_back(List[i]);
            }
            else if (strInStr(cKeyword, id) >= 0 || strInStr(id, cKeyword) >= 0)
            {
                ListNearly.push_back(List[i]);
            }
        }
    }
    else if (type == "Birthday")
    {
        Date a;
        sscanf(cKeyword,"%d/%d/%d", &a.day, &a.month, &a.year);

        // cout << "check day = " <<a.day<<a.month<<a.year; 

        for (int i = 0; i < Size; i++)
        {
            Date item = List[i].getDate();
            
            if (a.year == item.year ||a.month == item.month ||a.day == item.day )
            {
                ListNearly.push_back(List[i]);
            }
            if(a == item)
                ListExactly.push_back(List[i]);
        }
    }
    else if (type == "ALL")
    {
        for (int i = 0; i < Size; i++)
        {
            // search name
            char name[30];
            strcpy(name, List.at(i)->getname()); //->copy to new char[]
            touper(name);
            if (strcmp(cKeyword, name) == 0)
            {
                ListExactly.push_back(List[i]);
                ListNearly.push_back(List[i]);
                continue;
            }
            else if (strInStr(cKeyword, name) >= 0 || strInStr(name, cKeyword) >= 0)
            {
                ListNearly.push_back(List[i]);
                continue;
            }
     
            // search Class name
            char className[30];
            strcpy(className, List.at(i)->getclassName()); //->copy to new char[]
            touper(className);
            if (strcmp(cKeyword, className) == 0)
            {
                ListExactly.push_back(List[i]);
                ListNearly.push_back(List[i]);
                continue;
            }
            else if (strInStr(cKeyword, className) >= 0 || strInStr(className, cKeyword) >= 0)
            {
                ListNearly.push_back(List[i]);
                continue;
            }
     

            // search student code
            char id[30];
            strcpy(id, List.at(i)->getstudentCode()); //->copy to new char[]
            touper(id);
            if (strcmp(cKeyword, id) == 0)
            {
                ListExactly.push_back(List[i]);
                ListNearly.push_back(List[i]);
                continue;
            }
            else if (strInStr(cKeyword, id) >= 0 || strInStr(id, cKeyword) >= 0)
            {
                ListNearly.push_back(List[i]);
                continue;
            }
     
            // BirthDay
            int year = List[i].getYear();
            int y;
            y = atoi(cKeyword);
            if (y == year)
            {
                ListExactly.push_back(List[i]);
                ListNearly.push_back(List[i]);
            }
        }
    }

    if (accuracy == "Exactly")
    {
        if (ListExactly.getN() == 0)
        {
            // system("cls");
            gotoxy(3,36);
            cout << "\nNo solution found!";
        }
        else{
            displayStudentList(ListExactly);
        }
    }
    else
    {
        if (ListNearly.getN() == 0){
            gotoxy(0,36);
            cout << "\nNo solution found!";
        }
        else
            displayStudentList(ListNearly);
    }
}

enum
{
    cntt1 = 0,
    cntt2 = 1,
    an = 2,
    bd = 3,
    tlpk = 4,
    tlhq = 5,
    nl = 6,
    dt = 7
};
// struct Count
// {
//     int xsac = 0, gioi = 0, kha = 0, tbinh = 0, yeu = 0, total = 0;
// };

void PhanLoai(Count &T, double avg)
{
    T.total++;
    if (avg >= 9)
    {
        T.xsac++;
    }
    else if (avg >= 8 )
    {
        T.gioi++;
    }
    else if (avg >= 6.5)
    {
        T.kha++;
    }
    else if (avg >= 5 )
    {
        T.tbinh++;
    }
    else
    {
        T.yeu++;
    }
    // cout <<left <<setw(10) << avg <<" | "<< T.xsac << " " << T.gioi << " " <<T.kha << " " <<T.tbinh << " " <<T.yeu;
}
// Statistic student :  class, classification
void Statistic(string type, Student_list &List)
{
    system("cls");
    string Class[20]; // mang ten lop
    int num[20], nClass = 0;
    Count T[20];
    SetTextColor(7);

    Student_list st_List = List;
    Sort("ClassName", "QuickSort", st_List);
    Sort("ClassName", "QuickSort", st_List);

    string strName;
    toString(strName, st_List[0].getclassName());
    Class[nClass] = strName;
    double avg = st_List[0].getDiemTb();
    PhanLoai(T[0], avg);
    num[nClass++] = 1;


    for (int i = 1; i < st_List.getN(); i++)
    {
        // cout << left << setw(10) << st_List[i].getname() << " | ";
        string className;
        toString(className, st_List[i].getclassName());
        double avg = st_List[i].getDiemTb();
        for (int j = 0; j < nClass; j++)
        {
            if (className == Class[j]){
               
                PhanLoai(T[j], avg);
                num[j]++;
                // cout << Class[j] << " - num: " << num[j]<<endl;
                break;
            }else if (j == nClass - 1){
            // cout << j << " : "<< Class[j]  << endl;
                num[nClass] = 1;
                // cout << num[nClass] << "-" << Class[j] << endl;
                Class[nClass] = className;
                PhanLoai(T[nClass], avg);
                nClass++;
                break;
            }
        }
    }

    if (type == "class")
    {
        SetTextColor(7);
        // cout << "kiet check = " << nClass << endl;
        cout << "Number of student in class:";
        for (int i = 0; i < nClass; i++)
        {
            cout << endl;
            cout << Class[i] << "\tNum: " << num[i];
        }
        int total = 0;
        for (int i = 0; i < nClass; i++)
            total += num[i];
        SetTextColor(12);
        cout << "\nTotal: " << total;
        SetTextColor(7);


        char tenbieudo[50] = "BIEU DO HOC VIEN CAC LOP";
        BieuDo bieudoClass(45,38, tenbieudo,nClass);
        bieudoClass.ShowClass(1);
        int x = 45;
        for (int i = 0; i < nClass; i++)
        {
            char temp[20];
            toChar(Class[i],temp);
            bieudoClass.vecot(x,(int)num[i]*100/total,temp);
        }
        bieudoClass.veOx();
        


    }
    else if (type == "classification")
    {
        gotoxy(0,0);
        cout << "Classifacation: \n\n";
        for (int i = 0; i < nClass; i++)
        {
            SetTextColor(11);
            cout << Class[i] << ": " << T[i].total << endl;
            SetTextColor(7);
            cout << "XS: \t" << T[i].xsac << "\t" << round((double)(T[i].xsac) / T[i].total * 10000) / 100 << "%";
            cout << "\nGioi: \t" << T[i].gioi << "\t" << round((double)(T[i].gioi) / T[i].total * 10000) / 100 << "%";
            cout << "\nKha: \t" << T[i].kha << "\t" << round((double)(T[i].kha) / T[i].total * 10000) / 100 << "%";
            cout << "\nTB: \t" << T[i].tbinh << "\t" << round((double)(T[i].tbinh) / T[i].total * 10000) / 100 << "%";
            cout << "\nYeu: \t" << T[i].yeu << "\t" << round((double)(T[i].yeu) / T[i].total * 10000) / 100 << "%";
            cout << endl
                 << endl;
        }
        for (int i = 0; i < nClass; i++)
        {
            T[nClass + 1].xsac += T[i].xsac;
            T[nClass + 1].gioi += T[i].gioi;
            T[nClass + 1].kha += T[i].kha;
            T[nClass + 1].tbinh += T[i].tbinh;
            T[nClass + 1].yeu += T[i].yeu;
        }
        T[nClass + 1].total = List.getN();
        SetTextColor(12);
        cout << "Total:  " << T[nClass + 1].total << endl;
        SetTextColor(7);
        cout << "XS: \t" << T[nClass + 1].xsac << "\t" << round((double)(T[nClass + 1].xsac) / T[nClass + 1].total * 10000) / 100 << "%";
        cout << "\nGioi: \t" << T[nClass + 1].gioi << "\t" << round((double)(T[nClass + 1].gioi) / T[nClass + 1].total * 10000) / 100 << "%";
        cout << "\nKha: \t" << T[nClass + 1].kha << "\t" << round((double)(T[nClass + 1].kha) / T[nClass + 1].total * 10000) / 100 << "%";
        cout << "\nTB: \t" << T[nClass + 1].tbinh << "\t" << round((double)(T[nClass + 1].tbinh) / T[nClass + 1].total * 10000) / 100 << "%";
        cout << "\nYeu: \t" << T[nClass + 1].yeu << "\t" << round((double)(T[nClass + 1].yeu) / T[nClass + 1].total * 10000) / 100 << "%";
        cout << endl
             << endl;
        
        char tenbieudo[50] = "BIEU DO PHAN LOAI HOC VIEN ";

        BieuDo bieudoClass(45,38, tenbieudo,nClass);
        bieudoClass.ShowClass(2);
        int x = 45;
        for (int i = 0; i < nClass; i++)
        {
            char temp[20];
            toChar(Class[i],temp);
            bieudoClass.vecot(x,T[i],temp);
        }
        bieudoClass.veOx();


        
    }
    // fontsize(0, 24);
    int x;
    while (true)
    {
        x = key();
        if (x == 2)
            break;
    }
    system("cls");
}

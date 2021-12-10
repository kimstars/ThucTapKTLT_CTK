#pragma once 
#include <iostream>
#include <vector>
#include <windows.h>
#include <string.h>
#include <math.h>
#include "Student.h"
#include "rlutil.h"
#include "Input.h"


using namespace std;

typedef LinkedList Student_list;

void Search(string type, string keyword, string accuracy, Student_list List)
{
    Student_list ListExactly;
    Student_list ListNearly;
    ListExactly.clear();
    ListNearly.clear();
    char cKeyword[40];
    toChar(keyword, cKeyword);
    strcpy(cKeyword, chuanhoaXau(cKeyword));
    // cout << "kiet : "<<cKeyword;
    int Size = List.getN();

    if (type == "Name")
    {

        for (int i = 0; i < Size; i++)
        {
            char name[40];
            strcpy(name, List.at(i)->getname()); //->copy to new char[]
            // cout << name << "|" ;
            chuanhoaXau(name);
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
            chuanhoaXau(className);
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
            chuanhoaXau(id);
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
            chuanhoaXau(name);
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
            chuanhoaXau(className);
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
            chuanhoaXau(id);
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
            gotoxy(50,33);
            SetTextColor(RED);
            cout << "No solution found!";
            SetTextColor(14);

        }
        else{
            displayStudentList(ListExactly);
        }
    }
    else
    {
        if (ListNearly.getN() == 0){
            gotoxy(70,33);
            SetTextColor(RED);
            cout << "No solution found!";
            SetTextColor(14);

        }
        else
            displayStudentList(ListNearly);
    }
}


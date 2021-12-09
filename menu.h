/*******************************************************/
/** define all menu to display on console              */
/*******************************************************/
#pragma once
#include <conio.h>
#include <windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "Input.h"
#include "rlutil.h"
using namespace std;
int move()
{
    char c = getch();
    if ((int)c == -32)
        c = getch();
    switch ((int)c)
    {
    case 80:
        return 1; // cout << "Xuong";
    case 72:
        return 2; // cout << "Len";
    case 77:
        return 3; // cout << "Phai";
    case 75:
        return 4; // cout << "Trai";
    case 8:       // nut backspace
        return 7;
    case 27:
        return 8; // Nut ESC thoat
    case 13:
        return 5; // Nut Enter
    default:
        return 0; // cout << "Sai";
    }
}

class MENU
{
protected:
    string *item;
    int _numberOfItem;
    int preline = -1;
public:
    MENU()
    {
        item = new string[30];
        _numberOfItem = 6;

    };
    ~MENU(){};
    virtual void display()
    {
    }
    virtual void display(int start, int end, int step)
    {
    }

    int numberOfItem()
    {
        return _numberOfItem;
    }
    void selectItem(int line, int pos,int color=LIGHTCYAN)
    {
        box(pos, line * 3, 25, 2, YELLOW, 3, item[line]);
        if(preline != -1){
            box(pos, (preline) * 3, 25, 2, color, 3, item[preline]);
        }
        preline = line;
    }

    string *getItem()
    {
        return item;
    }
    int getNumberOfItem()
    {
        return _numberOfItem;
    }
};

/**Main menu **************************/
class MainMenu : public MENU
{
public:
    MainMenu()
    {
        item = new string[30];
        _numberOfItem = 6;

        item[0] = "1.Them sinh vien";
        item[1] = "2.In danh sach sinh vien";
        item[2] = "3.Sap xep  >";
        item[3] = "4.Tim kiem >";
        item[4] = "5.Thong ke >";
        
        item[5] = "6.Thoat";
    }
    ~MainMenu() {}
    void display();
    void display(int,int,int);
    void deleteMenu();
};
void MainMenu ::display(int start, int end, int step)
{
    for (int i = start; i < end; i++)
    {
        box(3, i * 3, 25, 2, LIGHTCYAN, 2, item[i - step]);
    }
}
void MainMenu ::display()
{
    for (int i = 0; i < _numberOfItem; i++)
    {
        box(3, i * 3, 25, 2, LIGHTCYAN, 2, item[i]);
    }
}

void MainMenu::deleteMenu()
{
    for (int i = 0; i < _numberOfItem; i++)
    {
        delbox(3, i * 3, 25, 2, 1, 2, item[i]);
    }
}

/**Search menu **************************/
class SearchMenu : public MENU
{
public:
    SearchMenu();
    ~SearchMenu() {}
    void display();
    void selectItem(int);
    void deleteMenu();
};
SearchMenu::SearchMenu()
{
    item = new string[30];
    _numberOfItem = 5;

    item[4] = "StudentCode";
    item[5] = "ClassName";
    item[6] = "Name";
    item[7] = "Birthday";
    item[8] = "ALL";
}

void SearchMenu::display()
{
    MainMenu mainMenu;
    mainMenu.display(0, 4, 0);
    mainMenu.display(9, 11, 6);
    for (int i = 4; i < 9; i++)
    {
        box(6, i * 3, 25, 2, BLUE, 2, item[i]);
    }
    
}

void SearchMenu::selectItem(int line)
{
    // box(6, line * 3, 25, 2, YELLOW, 3, item[line]);

    MENU::selectItem(line,6,BLUE);

}

void SearchMenu::deleteMenu()
{
    system("cls");
    MainMenu menu;
    menu.display();
}

/**Sort menu **************************/
class SortMenu : public MENU
{

public:
    SortMenu();
    ~SortMenu() {}
    void display();
    void selectItem(int line);
    void deleteMenu();
};
SortMenu::SortMenu()
{
    item = new string[30];
    _numberOfItem = 4;
    // Average, StudentCode, ClassName, Name, Birthday
    item[3] = "StudentCode";
    item[4] = "ClassName";
    item[5] = "Name";
    item[6] = "Birthday";
    item[7] = "AveragePoint";
}
void SortMenu::display()
{
    MainMenu mainMenu;
    mainMenu.display(0, 3, 0);
    mainMenu.display(8, 11, 5);
    for (int i = 3; i < 8; i++)
    {
        box(6, i * 3, 25, 2, BLUE, 2, item[i]);
    }

}

void SortMenu::selectItem(int line)
{
    // box(6, line * 3, 25, 2, YELLOW, 3, item[line]);
    MENU::selectItem(line,6,BLUE);

}
void SortMenu::deleteMenu()
{
    system("cls");
    MainMenu menu;
    menu.display();
}

/**Algorithm sort menu **************************/
class AlgorithmMenu : public MENU
{

public:
    AlgorithmMenu();
    ~AlgorithmMenu() {}
    void display();
    void deleteMenu();
    void selectItem(int);
};
//(chon, chen, quicksort, mergersort
AlgorithmMenu::AlgorithmMenu()
{
    item = new string[30];
    _numberOfItem = 5;
    item[3] = "SelectionSort";
    item[4] = "InsertionSort";
    item[5] = "QuickSort";
    item[6] = "BubbleSort";
}
void AlgorithmMenu::display()
{
    gotoxy(3, 36);
    cout << "Ban chon: Sap xep";
    SortMenu sortMenu;
    sortMenu.display();

    for (int i = 3; i <= 6; i++)
    {
        box(36, i * 3, 25, 2, LIGHTGREEN, 2, item[i]);
    }
    selectItem(3);
}

void AlgorithmMenu::selectItem(int line)
{
    // box(36, line * 3, 25, 2, YELLOW, 3, item[line]);
    MENU::selectItem(line,36,LIGHTGREEN);

}

void AlgorithmMenu::deleteMenu()
{
    system("cls");
    SortMenu sortMenu;
    sortMenu.display();
}

/**Statistic menu **************************/
class StatisticMenu : public MENU
{

public:
    StatisticMenu();
    ~StatisticMenu() {}
    void display();
    void selectItem(int);
    void deleteMenu();
};
StatisticMenu::StatisticMenu()
{
    item = new string[30];
    _numberOfItem = 4;
    item[5] = "Class";
    item[6] = "Classification";
}
void StatisticMenu::display()
{
    gotoxy(3, 36);
    cout << "Ban chon: Thong ke";
    MainMenu mainMenu;
    mainMenu.display(0, 5, 0);
    mainMenu.display(7, 8, 2);
    for (int i = 5; i < 7; i++)
    {
        box(6, i * 3, 25, 2, 1, 3, item[i]);
    }
    selectItem(5);
}

void StatisticMenu::selectItem(int line)
{
    // box(6, line * 3, 25, 2, YELLOW, 3, item[line]);
    MENU::selectItem(line,6,BLUE);

}
void StatisticMenu::deleteMenu()
{
    system("cls");
    MainMenu mainmenu;
    mainmenu.display();
}


/**search menu 2  (To enter keyword )**************************/
class Search2 : public MENU
{
public:
    Search2();
    ~Search2() {}
    void display();
    void selectItem(int);
    string enter_keyword();
    void deleteMenu();
};
// a box for get keyword to search
string Search2::enter_keyword()
{
    SetTextColor(7);
    gotoxy(0, 18);
    cout << "                                       ";
    /* Drawing frame to enter keyword */
    gotoxy(33, 7);
    printf("%c", 218);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 191);
    gotoxy(33, 8);
    printf("%c%30c\n", 179, 179);
    gotoxy(33, 8);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(33, 8);
    printf("%c%30c\n", 179, 179);
    gotoxy(33, 9);
    printf("%c", 192);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c", 217);
    /*-----------------------------------------------*/
    SetTextColor(11);
    gotoxy(33, 7);
    cout << "ENTER KEYWORD";
    SetTextColor(7);
    string str;
    gotoxy(37, 8);
    SetTextColor(10);
    getline(cin, str);
    SetTextColor(7);
    // Delete frame
    for (int i = 7; i <= 9; i++)
    {
        gotoxy(33, i);
        cout << "                                          ";
    }
    return str;
}
Search2::Search2()
{
    item = new string[30];
    _numberOfItem = 5;
    item[3] = "Muc do chinh xac >";
    item[4] = "Nearly";
    item[5] = "Exactly";
}
void Search2::display()
{
    gotoxy(3, 36);
    cout << "Ban chon: Tim kiem";
    SearchMenu searchMenu;
    searchMenu.display();
    gotoxy(36, 15);
    cout << "   " << item[3];
    for (int i = 4; i < 6; i++)
    {
        box(36, i * 3, 25, 2, 1, 2, item[i]);
    }
}

void Search2::selectItem(int line)
{
    MENU::selectItem(line,36,BLUE);
}
void Search2::deleteMenu()
{
    SearchMenu searchMenu;
    searchMenu.display();
}

#pragma once
#ifndef initial
#define initial
#include <stdio.h>
#include "rlutil.h"
#include "IO.h"
#include "displayMenu.h"





void drawInfo()
{
    fontsize(0,25);
    gotoxy(50, 0);
    SetTextColor(WHITE);
    cout << "HOC VIEN THUC HIEN : CHU TUAN KIET";
    fontsize(0,20);
}

void DisplayConsole()
{
    system("cls");
    SetColorBackground(35,35,35);
    system("MODE 300");
    // RemoveScrollbar();
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    DisableResizeWindow();
    hidecursor();
    SetConsoleTitle("QUAN LY DANH SACH SINH VIEN");
    drawInfo();
    displayMainMenu();
}

#endif
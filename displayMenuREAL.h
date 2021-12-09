#pragma once
#include <stdio.h>
#include "rlutil.h"
#include "IO.h"
#include "LinkedList.h"
#include "menu.h"
#include "Sort.h"
#include "search_statistic.h"

string type, algorithm, keyword, accuracy;

typedef LinkedList Student_list;
Student_list student_list;

const int noti = 36;

void Display_SortAlgorithm_Menu()
{
	AlgorithmMenu algorithmMenu;
	int x, line = 3;
	bool exit = false;
	algorithmMenu.display();

	while (!exit)
	{
		gotoxy(3, 36);
		x = move();

		switch (x)
		{

		case 1: // keyboard = down
		{
			line++;
			if (line > 6)
				line = 3;
			break;
		}

		case 2: // keyboard = up
		{
			line--;
			if (line < 3)
				line = 6;
			break;
		}
		case 3: // keyboard = right
		{
			break;
		}
		// nut enter:
		case 5:
		{
			algorithm = algorithmMenu.getItem()[line];
			algorithmMenu.selectItem(line);
			gotoxy(10, noti);
			cout << "Tuy chon: " << algorithm << endl;
			SetTextColor(11);
			gotoxy(10, noti + 1);
			cout << "Sortting . . .";
			cout << type;
			Sort(type, algorithm, student_list);
			SetTextColor(7);
			displayStudentList(student_list);

			algorithmMenu.display();
			gotoxy(10, noti + 2);
			cout << "Tuy chon: " << type << endl;
			break;
		}
		// keyboard =  ESC || backspace || left
		case 7:
		case 4:
		case 8:
		{
			exit = true;
			system("cls");
			algorithmMenu.deleteMenu();

			break;
		}
		}

		// system("color 01");
		if (!exit)
			algorithmMenu.selectItem(line);
	}
}

void Display_Sort_Menu()
{
	system("cls");
	SortMenu sortMenu;
	int x, line = 3;
	bool exit = false;
	sortMenu.display();

	while (!exit)
	{
		gotoxy(3, noti);
		SetTextColor(RED);
		cout << "Ban chon: Sap xep";
		x = move();

		switch (x)
		{
		case 1: // keyboard = down
		{
			line++;
			if (line > 7)
				line = 3;
			break;
		}

		case 2: // keyboard = up
		{
			line--;
			if (line < 3)
				line = 7;
			break;
		}
		case 3: // keyboard = right

		// nut enter:
		case 5:
		{
			type = sortMenu.getItem()[line];
			gotoxy(3, noti + 2);
			cout << "Tuy chon key sap xep: " << type;
			Display_SortAlgorithm_Menu();
			break;
		}
		// keyboard = left || ESC || backspace
		case 7:
		case 4:
		case 8:
		{
			exit = true;
			system("cls");
			sortMenu.deleteMenu();
			break;
		}
		}
		if (!exit)
			sortMenu.selectItem(line);
		// system("color 01");
	}

	// system("cls");
}

void Display_Search2_Menu()
{
	// system("cls");
	SetTextColor(7);
	Search2 search2;
	int x, line = 4;
	bool exit = false;
	search2.display();

	while (!exit)
	{
		gotoxy(0, 15);
		x = move();

		switch (x)
		{

		case 1: // keyboard = down
		{
			line++;
			if (line > 5)
				line = 4;
			break;
		}

		case 2: // keyboard = up
		{
			line--;
			if (line < 4)
				line = 5;
			break;
		}
		case 3: // keyboard = right
		{
			break;
		}

		// nut enter:
		case 5:
		{

			accuracy = search2.getItem()[line];
			SetTextColor(7);
			gotoxy(40, noti);
			cout << "Tuy chon: " << accuracy << endl;
			SetTextColor(11);
			/*Do sth */
			showPointer();
			keyword = search2.enter_keyword();
			// if(accuracy == "Birthday")
			hidePointer();
			gotoxy(40, noti + 1);
			cout << "Key word: " << keyword;
			Search(type, keyword, accuracy, student_list);
			search2.display();
			gotoxy(3, noti);
			cout << "                                                    ";
			gotoxy(20, noti+2);
			cout << "Tuy chon: " << type;
			break;
		}
		// keyboard = left || ESC || backspace
		case 7:
		case 4:
		case 8:
		{
			exit = true;
			system("cls");
			search2.deleteMenu();
			break;
		}
		}

		// system("color 01");
		if (!exit)
			search2.selectItem(line);
	}

}

void Display_Search_Menu()
{
	system("cls");
	SetTextColor(7);
	SearchMenu searchMenu;
	int x, line = 4;
	bool exit = false;
	searchMenu.display();
	gotoxy(3, 36);
	cout << "Ban chon: Tim kiem";

	while (!exit)
	{
		gotoxy(0, 15);
		x = move();
		gotoxy(3, line);
		switch (x)
		{

		case 1: // keyboard = down
		{
			line++;
			if (line > 8)
				line = 4;
			break;
		}

		case 2: // keyboard = up
		{
			line--;
			if (line < 4)
				line = 8;
			break;
		}
		case 3: // keyboard = right
		// nut enter:
		case 5:
		{
			gotoxy(3, 36);
			cout << "                                                    ";
			// xu li voi line la vi tri dong co cac lua chon
			gotoxy(3, noti + 1);
			type = searchMenu.getItem()[line];
			cout << "Tuy chon: " << type;
			/*if (type == "ALL") {
				showPointer();
				Search2 s;
				keyword = s.enter_keyword();
				hidePointer();
				gotoxy(0,18); cout << "                                 ";
				gotoxy(0,18); cout << "Key word: " << keyword;
				//Ham tim kiem voi type = ALL
			} else*/
			searchMenu.selectItem(line);
			Display_Search2_Menu();
			break;
		}
		// keyboard = left || ESC || backspace
		case 7:
		case 4:
		case 8:
		{
			exit = true;
			system("cls");
			searchMenu.deleteMenu();
			break;
		}
		}

		// system("color 01");
		if (!exit)
			searchMenu.selectItem(line);
		// gotoxy(6, line);
		// cout << searchMenu.getItem()[line];
	}
	// system("color 01");
}

void Display_Statistic_Menu()
{
	system("cls");
	SetTextColor(7);
	StatisticMenu staMenu;
	int x, line = 5;
	bool exit = false;
	staMenu.display();
	SetTextColor(12);

	while (!exit)
	{
		gotoxy(3, 36);
		x = move();
		gotoxy(3, line);
		cout << " "; // xoa con tro ">" chi dinh dong dang chon
		switch (x)
		{

		case 1: // keyboard = down
		{
			line++;
			if (line > 6)
				line = 5;
			break;
		}

		case 2: // keyboard = up
		{
			line--;
			if (line < 5)
				line = 6;
			break;
		}
		case 3: // keyboard = right
		// nut enter:
		case 5:
		{
		                                            
			// xu li voi line la vi tri dong co cac lua chon
			gotoxy(3, noti+1);
			cout << "Tuy chon: " << staMenu.getItem()[line];
			if (line == 5)
				type = "class";
			else
				type = "classification";
			Statistic(type, student_list);
			staMenu.display();
			break;
		}
		// keyboard = left || ESC || backspace
		case 7:
		case 4:
		case 8:
		{
			exit = true;
			staMenu.deleteMenu();
			break;
		}
		}

		// system("color 01");
		// SetTextColor(12);
		if (!exit)
			staMenu.selectItem(line);
	}
	// system("color 01");

	// system("cls");
}

void displayMainMenu()
{
	student_list.read("out450.bin");

	MainMenu mainMenu;
	mainMenu.display();
	int x, line = 0;
	bool exit = false;
	mainMenu.selectItem(line, 3);

	while (!exit)
	{
		x = move();
		switch (x)
		{
		case 1: // keyboard = down
		{
			line++;
			if (line >= mainMenu.getNumberOfItem())
				line = 0;
			break;
		}
		case 2: // keyboard = up
		{
			line--;
			if (line < 0)
				line = mainMenu.getNumberOfItem() - 1;
			break;
		}
		case 4: // keyboard = left
		{
			break;
		}
		case 3: // keyboard = right

		case 5: // nut enter:
		{

			switch (line)
			{
			case 0:
			{
				// Nhap sinh vien
				showPointer(); // Hien thi con tro nhap nhay de nhap
				SetTextColor(7);
				// Nhap sinh vien, tra ve danh sach sinh vien da nhap
				enter(student_list);
				// Tra lai giao dien menu chinh ban dau
				system("cls");
				mainMenu.display();
				// An con tro nhap nhay
				hidePointer();
				break;
			}
			case 1:
			{ // In danh sach sinh vien
				gotoxy(0, 16);
				displayStudentList(student_list);
				cout << "nhap stt sinh vien can sua :"; int i;
				// cin>> i;
				// Edit(student_list, i);
				//  Tra lai giao dien menu chinh ban dau
				system("cls");
				mainMenu.display();
				break;
			}
			case 2:
			{ // Tuy chon sap xep
				Display_Sort_Menu();
				break;
			}
			case 3:
			{ // Tuy chon tim kiem
				Display_Search_Menu();
				break;
			}
			case 4:
			{ // Tuy chon thong ke
				Display_Statistic_Menu();
				break;
			}
			case 5:
			{ // Thoat
				exit = true;
				break;
			}
			}
			break;
		}
		case 8: // ESC
			exit = true;
			system("cls");
			mainMenu.deleteMenu();
			break;
		}
		// system("color ");
		// SetColor(CYAN);
		if (!exit)
			mainMenu.selectItem(line, 3);
	}
	// system("color 01");

	system("cls");

	box(4, 20, 50, 2, GREEN, RED, "Ban muon ghi ket qua vao file khong (enter|esc)?");
	int cs = key();
	if (cs == 1)
	{
		// Ghi danh sach sinh vien vao file
		student_list.write("out450.bin");
		// showPointer();
		cout << "Write data to file: ";
		cout << "successful! \n";
	}
}
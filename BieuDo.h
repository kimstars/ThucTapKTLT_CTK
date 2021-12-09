/*****************************************************************/
/** Vẽ biểu đồ tỷ lệ phần trăm số học sinh và phân loại học sinh**/
/*****************************************************************/

#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "rlutil.h"

using namespace std;

struct Count
{
	int xsac = 0, gioi = 0, kha = 0, tbinh = 0, yeu = 0, total = 0;
};

class BieuDo
{
private:
	int xbieudo;
	int ybieudo;
	char *tenbieudo;
	int socot;
	int height = 100, width;

public:
	BieuDo()
	{
		xbieudo = 30;
		ybieudo = 45;
		tenbieudo = new char[50];
	}
	BieuDo(int x, int y, char *tenbieudo, int socot)
	{
		xbieudo = x;
		ybieudo = y;
		this->tenbieudo = tenbieudo;
		this->socot = socot;
		this->width = (socot + 1) * 4;
	}

	~BieuDo(){};

	void drawClass(int);

	void vecot(int &x, int chieucao, char *tencot);
	void vecot(int &x, Count T, char *tencot);
	void veOy();
	void veOx();

	void fontsize(int a, int b);


	void ShowClass(int bang)
	{
		fontsize(0, 12);
		drawClass(bang);
		veOy();
	}

	void drawGach()
	{
		for (int i = 0; i < width; i++)
		{
			cout << " - ";
		}
	}
};

void BieuDo::fontsize(int a, int b)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

void BieuDo::drawClass(int bang)
{
	// ve gach oy
	SetTextColor(14);
	int y = round((int)height / 30);
	for (int i = 1; i < 10; i++)
	{
		gotoxy(xbieudo - 2, ybieudo - i * y);
		printf("%d", i * 10);
		drawGach();
	}
	gotoxy(xbieudo - 5, ybieudo - 10 * y);
	printf("100");
	printf("%c", 37);
	drawGach();

	// Chu thich

	// gotoxy(xbieudo + 10, ybieudo + 11);
	// SetTextColor(56);
	// printf("   ");
	SetTextColor(14);
	gotoxy(xbieudo + 15, ybieudo + 5);
	cout << tenbieudo;
	// printf("BIEU DO PHAN LOAI HOC SINH KHA GIOI XUAT SAC");

	if (bang == 1)
	{
		gotoxy(xbieudo + 10, ybieudo + 8);
		SetTextColor(57);
		printf("   ");
		SetTextColor(14);
		gotoxy(xbieudo + 15, ybieudo + 8);
		printf("Ty le hoc sinh cac lop");
	}
	else if (bang == 2)
	{
		gotoxy(150 + 10, ybieudo / 2 + 8);
		SetTextColor(78);
		printf("   ");
		SetTextColor(14);
		gotoxy(150 + 15, ybieudo / 2 + 8);
		printf("Hoc Sinh XS");

		gotoxy(150 + 10, ybieudo / 2 + 10);
		SetTextColor(57);
		printf("   ");
		SetTextColor(14);
		gotoxy(150 + 15, ybieudo / 2 + 10);
		printf("Hoc Sinh Gioi");

		gotoxy(150 + 10, ybieudo / 2 + 12);
		SetTextColor(45);
		printf("   ");
		SetTextColor(14);
		gotoxy(150 + 15, ybieudo / 2 + 12);
		printf("Hoc Sinh Kha");

		gotoxy(150 + 10, ybieudo / 2 + 14);
		SetTextColor(99);
		printf("   ");
		SetTextColor(14);
		gotoxy(150 + 15, ybieudo / 2 + 14);
		printf("Hoc Sinh Trung binh");

		gotoxy(150 + 10, ybieudo / 2 + 16);
		SetTextColor(80);
		printf("   ");
		SetTextColor(14);
		gotoxy(150 + 15, ybieudo / 2 + 16);
		printf("Hoc Sinh Yeu");
	}
}

void BieuDo::vecot(int &x, int chieucao, char *tencot)
{
	x += 10;
	int drawcot = chieucao * (ybieudo - 5) / 100;
	gotoxy(x, ybieudo - drawcot - 4);
	SetTextColor(14);
	cout << chieucao << "%";
	gotoxy(x, ybieudo + 2);
	printf("%s", tencot);
	for (int i = ybieudo - drawcot + 1; i <= ybieudo; i++)
	{
		SetTextColor(57);
		gotoxy(x, i - 1);
		printf("    ");
		SetTextColor(14);
	}
}

void BieuDo::vecot(int &x, Count T, char *tencot)
{
	x += 10;
	// int drawcot = chieucao*(ybieudo-5)/100;
	int y0 = round((int)T.xsac * (ybieudo - 7) / T.total);
	int y1 = round((int)T.gioi * (ybieudo - 7) / T.total);
	int y2 = round((int)T.kha * (ybieudo - 7) / T.total);
	int y3 = round((int)T.tbinh * (ybieudo - 7) / T.total);
	// int y4 = round((int)T.yeu * (ybieudo - 7) / T.total);
	int y4 = round((int)(ybieudo - 7)- y0 - y1 - y2 - y3);
	

	int y = ybieudo;

	gotoxy(x, ybieudo + 2);
	printf("%s", tencot);

	if (y0)
	{

		for (int i = y - y0 + 1; i <= y; i++)
		{
			SetTextColor(78);
			gotoxy(x, i - 1);
			printf("    ");
			SetTextColor(14);
		}
		y -= y0;
	}
	
	if (y1)
	{

		for (int i = y - y1 + 1; i <= y; i++)
		{
			SetTextColor(57);
			gotoxy(x, i - 1);
			printf("    ");
			SetTextColor(14);
		}
		y -= y1;
	}

	if (y2)
	{

		for (int i = y - y2 + 1; i <= y; i++)
		{
			SetTextColor(45);
			gotoxy(x, i - 1);
			printf("    ");
			SetTextColor(14);
		}
		y -= y2;
	}

	if (y3)
	{

		for (int i = y - y3 + 1; i <= y; i++)
		{
			SetTextColor(99);
			gotoxy(x, i - 1);
			printf("    ");
			SetTextColor(14);
		}
		y -= y3;
	}

	if (y4)
	{

		for (int i = y - y4 + 1; i <= y; i++)
		{
			SetTextColor(80);
			gotoxy(x, i - 1);
			printf("    ");
			SetTextColor(14);
		}
		y -= y4;
	}

	for (int i = 8 ; i >= 0; i--)
		{
			SetTextColor(BLACK);
			gotoxy(x, i - 1);
			printf("    ");
			SetTextColor(14);
		}


}

void BieuDo::veOy()
{
	for (int i = ybieudo; i > 5; i--)
	{
		gotoxy(xbieudo, i);
		printf("%c", 179);
	}
	gotoxy(xbieudo, 5);
	printf("%c", 30);

	gotoxy(xbieudo, ybieudo);
	printf("%c", 192);
}

void BieuDo::veOx()
{
	gotoxy(xbieudo + 1, ybieudo);
	for (int i = 0; i < width * 3; i++)
		printf("%c", 196);
	printf("%c", 16);
}
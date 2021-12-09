
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "../rlutil.h"

using namespace std;



class BieuDo{
private:
	int xbieudo;
	int ybieudo;
	char *tenbieudo;
public:
	BieuDo(){
		xbieudo = 30;
		ybieudo = 55;
		tenbieudo = new char[50];
	}
	BieuDo(int x,int y,char *tenbieudo){
		xbieudo = x;
		ybieudo = y;
		tenbieudo = new char[50];
		this->tenbieudo =tenbieudo ; 
	}
	~BieuDo(){};

	void drawGach(int,int, string);
	void vecot(int &x,int y,int chieucao,string tencot);
	void veOy();
	void veOx();

	void fontsize(int a, int b);

	void Show(){
		fontsize(0, 12);
		drawGach(xbieudo,ybieudo,tenbieudo);
		veOy();
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

void BieuDo::drawGach(int xbieudo, int ybieudo, string tenbieudo)
{
	SetTextColor(14);
	int vebieudo, vesolieu;
	xbieudo = 30;
	ybieudo = 55;

	gotoxy(xbieudo - 2, ybieudo);
	printf("0");
	gotoxy(xbieudo - 2, ybieudo - 5);
	printf("10 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 10);
	printf("20 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 15);
	printf("30 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 20);
	printf("40 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 25);
	printf("50 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 30);
	printf("60 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 35);
	printf("70 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 40);
	printf("80 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 2, ybieudo - 45);
	printf("90 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _");
	gotoxy(xbieudo - 5, ybieudo - 49);
	printf("100%c  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _", 37);


	//Chu thich
	gotoxy(xbieudo + 10, ybieudo + 8);
	SetTextColor(78);
	printf("   ");
	gotoxy(xbieudo + 10, ybieudo + 11);
	SetTextColor(56);
	printf("   ");
	SetTextColor(14);
	gotoxy(xbieudo + 15, ybieudo + 5);


	// printf("BIEU DO PHAN LOAI HOC SINH KHA GIOI XUAT SAC");
	// printf("%s",tenbieudo);
	cout << tenbieudo;

	gotoxy(xbieudo + 15, ybieudo + 8);
	printf("Hoc Sinh Kha, Gioi, Xuat Sac");
	gotoxy(xbieudo + 15, ybieudo + 11);
	printf("Hoc Sinh Con Lai");
	// truc Oy
	
	// truc Ox
	// gotoxy(xbieudo, ybieudo);
	// for (int i = 0; i < 73; i++)
	// 	printf("%c", 196);
	// printf("%c", 16);
	

}


void BieuDo::vecot(int &x,int y,int chieucao,string tencot){
	x += 10;

	chieucao /= 2;
	gotoxy(x, y + 2);
	// printf("%s", tencot);
	cout << tencot;
	for (int i = y - chieucao + 1; i <= y; i++)
	{
		SetTextColor(78);
		gotoxy(x, i-1);
		printf("    ");
		SetTextColor(14);
	}
}

void BieuDo::veOy(){
	for (int i = ybieudo - 1; i > 5; i--)
	{
		gotoxy(xbieudo, i);
		printf("%c", 179);
	}
	gotoxy(xbieudo, 5);
	printf("%c", 30);
	gotoxy(xbieudo, ybieudo);
	printf("%c", 192);

}

void BieuDo::veOx(){
	gotoxy(xbieudo+1, ybieudo);
	for (int i = 0; i < 73; i++)
		printf("%c", 196);
	printf("%c", 16);

}

int main()
{
	BieuDo bieudo(30,55,"BIEU DO PHAN LOAI HOC SINH KHA GIOI XUAT SAC");
	bieudo.Show();

	int n = 4;
	int xbieudo = 30;
	int ybieudo = 55;
	char s[10][10] = {"gioi","kha","tb","yeu"};
	double diem[10] ={10, 14, 5, 3};
	int phantram[10];
	double tong =0;
	for(int i =0; i < n; i++){
		tong += diem[i];
	}
	int x = xbieudo;

	for(int i = 0; i < n; i++){
		phantram[i] = (int)diem[i]*100/tong;
		cout << phantram[i];
		bieudo.vecot(x,ybieudo,phantram[i],s[i]);
	}

	bieudo.veOx(xbieudo,ybieudo);



}
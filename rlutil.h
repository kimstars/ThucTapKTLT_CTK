#pragma once
#ifndef _RLUTIL_H
#define _RLULTI_H
#if 0
#define RLUTIL_STRING_T char*
#endif

#ifndef RLUTIL_INLINE
	#ifdef _MSC_VER
		#define RLUTIL_INLINE __inline
	#else
		#define RLUTIL_INLINE static __inline__
	#endif
#endif

#include <stdio.h> 
#include <iostream>
#include <string.h> 
using namespace std;

RLUTIL_INLINE void locate(int x, int y); // Forward declare for C to avoid warnings

#include <windows.h>  // for WinAPI and Sleep()
#define _NO_OLDNAMES  // for MinGW compatibility
#include <conio.h>    // for getch() and kbhit()
#define getch _getch
#define kbhit _kbhit

#ifndef gotoxy
RLUTIL_INLINE void gotoxy(int x, int y) {
	locate(x,y);
}
#endif

#ifndef RLUTIL_STRING_T
	typedef const char* RLUTIL_STRING_T;
#endif

#define RLUTIL_PRINT(st) printf("%s", st)
enum {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	GREY,
	DARKGREY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

const RLUTIL_STRING_T ANSI_CLS                = "\033[2J\033[3J";
const RLUTIL_STRING_T ANSI_CONSOLE_TITLE_PRE  = "\033]0;";
const RLUTIL_STRING_T ANSI_CONSOLE_TITLE_POST = "\007";
const RLUTIL_STRING_T ANSI_ATTRIBUTE_RESET    = "\033[0m";
const RLUTIL_STRING_T ANSI_CURSOR_HIDE        = "\033[?25l";
const RLUTIL_STRING_T ANSI_CURSOR_SHOW        = "\033[?25h";
const RLUTIL_STRING_T ANSI_CURSOR_HOME        = "\033[H";
const RLUTIL_STRING_T ANSI_BLACK              = "\033[22;30m";
const RLUTIL_STRING_T ANSI_RED                = "\033[22;31m";
const RLUTIL_STRING_T ANSI_GREEN              = "\033[22;32m";
const RLUTIL_STRING_T ANSI_BROWN              = "\033[22;33m";
const RLUTIL_STRING_T ANSI_BLUE               = "\033[22;34m";
const RLUTIL_STRING_T ANSI_MAGENTA            = "\033[22;35m";
const RLUTIL_STRING_T ANSI_CYAN               = "\033[22;36m";
const RLUTIL_STRING_T ANSI_GREY               = "\033[22;37m";
const RLUTIL_STRING_T ANSI_DARKGREY           = "\033[01;30m";
const RLUTIL_STRING_T ANSI_LIGHTRED           = "\033[01;31m";
const RLUTIL_STRING_T ANSI_LIGHTGREEN         = "\033[01;32m";
const RLUTIL_STRING_T ANSI_YELLOW             = "\033[01;33m";
const RLUTIL_STRING_T ANSI_LIGHTBLUE          = "\033[01;34m";
const RLUTIL_STRING_T ANSI_LIGHTMAGENTA       = "\033[01;35m";
const RLUTIL_STRING_T ANSI_LIGHTCYAN          = "\033[01;36m";
const RLUTIL_STRING_T ANSI_WHITE              = "\033[01;37m";
const RLUTIL_STRING_T ANSI_BACKGROUND_BLACK   = "\033[40m";
const RLUTIL_STRING_T ANSI_BACKGROUND_RED     = "\033[41m";
const RLUTIL_STRING_T ANSI_BACKGROUND_GREEN   = "\033[42m";
const RLUTIL_STRING_T ANSI_BACKGROUND_YELLOW  = "\033[43m";
const RLUTIL_STRING_T ANSI_BACKGROUND_BLUE    = "\033[44m";
const RLUTIL_STRING_T ANSI_BACKGROUND_MAGENTA = "\033[45m";
const RLUTIL_STRING_T ANSI_BACKGROUND_CYAN    = "\033[46m";
const RLUTIL_STRING_T ANSI_BACKGROUND_WHITE   = "\033[47m";

enum {
	KEY_ESCAPE  = 0,
	KEY_ENTER   = 1,
	KEY_SPACE   = 32,

	KEY_INSERT  = 2,
	KEY_HOME    = 3,
	KEY_PGUP    = 4,
	KEY_DELETE  = 5,
	KEY_END     = 6,
	KEY_PGDOWN  = 7,

	KEY_UP      = 14,
	KEY_DOWN    = 15,
	KEY_LEFT    = 16,
	KEY_RIGHT   = 17,

	KEY_F1      = 18,
	KEY_F2      = 19,
	KEY_F3      = 20,
	KEY_F4      = 21,
	KEY_F5      = 22,
	KEY_F6      = 23,
	KEY_F7      = 24,
	KEY_F8      = 25,
	KEY_F9      = 26,
	KEY_F10     = 27,
	KEY_F11     = 28,
	KEY_F12     = 29,

	KEY_NUMDEL  = 30,
	KEY_NUMPAD0 = 31,
	KEY_NUMPAD1 = 127,
	KEY_NUMPAD2 = 128,
	KEY_NUMPAD3 = 129,
	KEY_NUMPAD4 = 130,
	KEY_NUMPAD5 = 131,
	KEY_NUMPAD6 = 132,
	KEY_NUMPAD7 = 133,
	KEY_NUMPAD8 = 134,
	KEY_NUMPAD9 = 135
};

RLUTIL_INLINE int getkey(void) {
	int k = getch();
	switch(k) {
		case 0: {
			int kk;
			switch (kk = getch()) {
				case 71: return KEY_NUMPAD7;
				case 72: return KEY_NUMPAD8;
				case 73: return KEY_NUMPAD9;
				case 75: return KEY_NUMPAD4;
				case 77: return KEY_NUMPAD6;
				case 79: return KEY_NUMPAD1;
				case 80: return KEY_NUMPAD2;
				case 81: return KEY_NUMPAD3;
				case 82: return KEY_NUMPAD0;
				case 83: return KEY_NUMDEL;
				default: return kk - 59 + KEY_F1; // Function keys
			}}
		case 224: {
			int kk;
			switch (kk = getch()) {
				case 71: return KEY_HOME;
				case 72: return KEY_UP;
				case 73: return KEY_PGUP;
				case 75: return KEY_LEFT;
				case 77: return KEY_RIGHT;
				case 79: return KEY_END;
				case 80: return KEY_DOWN;
				case 81: return KEY_PGDOWN;
				case 82: return KEY_INSERT;
				case 83: return KEY_DELETE;
				default: return kk - 123 + KEY_F1; // Function keys
			}}
		case 13: return KEY_ENTER;
		case 27: return KEY_ESCAPE;
		default: return k;
	}
}

RLUTIL_INLINE int nb_getch(void) {
	if (kbhit()) return getch();
	else return 0;
}

RLUTIL_INLINE void cls(void) {
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD coordScreen = {0, 0};
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	const DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

	SetConsoleCursorPosition(hConsole, coordScreen);
}

RLUTIL_INLINE void locate(int x, int y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = x;
    Position.Y = y;
	SetConsoleCursorPosition(hStdout, Position);
}

RLUTIL_INLINE void setString(RLUTIL_STRING_T str) {
	unsigned int len = strlen(str);
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD numberOfCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
	WriteConsoleOutputCharacterA(hConsoleOutput, str, len, csbi.dwCursorPosition, &numberOfCharsWritten);
}

RLUTIL_INLINE void setChar(char ch) {
	const char buf[] = {ch, 0};
	setString(buf);
}

RLUTIL_INLINE void setCursorVisibility(char visible) {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo ); // Get current cursor size
	structCursorInfo.bVisible = (visible ? TRUE : FALSE);
	SetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
}

RLUTIL_INLINE void hidecursor() {
	setCursorVisibility(0);
}

RLUTIL_INLINE void showcursor() {
	setCursorVisibility(1);
}

RLUTIL_INLINE void msleep(unsigned int ms) {
	Sleep(ms);
}

RLUTIL_INLINE void anykey(RLUTIL_STRING_T msg) {
	if (msg)
		RLUTIL_PRINT(msg);
	getch();
}

void DisableResizeWindow() {
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void RemoveScrollbar() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = 
    {
        (SHORT) (info.srWindow.Right - info.srWindow.Left + 1),
        (SHORT) (info.srWindow.Bottom - info.srWindow.Top + 1)
    };
    SetConsoleScreenBufferSize(handle, new_size);
}
void DisableCtrButton(bool Close, bool Min, bool Max) {
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    if (Close == 1) {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1) {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1) {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void SetWindowSize(SHORT width, SHORT height) {
	HWND hwnd = GetConsoleWindow();
	RECT rect = {0, 0, height, width};
	MoveWindow(hwnd, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,TRUE);
}

void DisableSelection() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void SetColorBackground(int Red, int Green, int Blue) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
    csbiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hConsoleOutput, &csbiex);
    csbiex.ColorTable[0] = RGB(Red, Green, Blue); // Xam
	csbiex.ColorTable[1] = RGB(0, 154, 255); // Xanh Duong
	csbiex.ColorTable[2] = RGB(239, 247, 1); // Vang
	csbiex.ColorTable[3] = RGB(1, 247, 75);  // Xanh La cay
	csbiex.ColorTable[4] = RGB(255, 255, 255); //Trang
    SetConsoleScreenBufferInfoEx(hConsoleOutput, &csbiex);
}

void SetTextColor(int colorCode) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, colorCode);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

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

void hidePointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

void showPointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

void fontsize(int a, int b)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
    lpConsoleCurrentFontEx->dwFontSize.X = a;
    lpConsoleCurrentFontEx->dwFontSize.Y = b;
    SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

void append(char* subject, const char insert[], int pos) {
    char buf[31] = {}; 
    memset(buf, '\0', 31);
    strncpy(buf, subject, pos); // copy at most first pos characters
    int len = strlen(buf);
    strcpy(buf + len, insert); // copy all of insert[] at the end
    len += strlen(insert);  
    strcpy(buf + len, subject + pos); 
    strcpy(subject, buf);   
}



// Xử lý text

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

#endif


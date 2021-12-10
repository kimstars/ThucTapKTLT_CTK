#pragma once
#include "rlutil.h"



#ifndef draw
#define draw
// Mau


// Vẽ giao diện Input data (thêm sinh viên)
void drawInputMenu(string title)
{
    SetTextColor(2);
    /** Ve khung de nhap sinh vien ***************/
    // hang dau
    gotoxy(20, 2);
    printf("%c", 218);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 191);
    gotoxy(20, 3);
    printf("%c%30c\n", 179, 179);
    // hang 2
    gotoxy(20, 4);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 5);
    printf("%c%30c\n", 179, 179);
    // hang 4
    gotoxy(20, 6);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 7);
    printf("%c%30c\n", 179, 179);
    // hang 6
    gotoxy(20, 8);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 9);
    printf("%c%30c\n", 179, 179);
    // hang 8
    gotoxy(20, 10);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 11);
    printf("%c%30c\n", 179, 179);
    // hang cuoi
    gotoxy(20, 12);
    printf("%c", 192);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c", 217);

    /* Neu muon ve rieng mot khung thi dung code nay */
    /*gotoxy(20,14); printf("%c",218);	for(int i=0;i<29;i++)	printf("%c",196); printf("%c\n",191);	gotoxy(20,15);printf("%c%30c\n",179,179);
    gotoxy(20,15);printf("%c",195);	for(int i=0;i<29;i++)	printf("%c",196); printf("%c\n",180);	gotoxy(20,15);printf("%c%30c\n",179,179);
    gotoxy(20,16);printf("%c",192); for(int i=0;i<29;i++)   printf("%c",196); printf("%c",217);*/
    /*-----------------------------------------------*/

    /* Ve hai duong doc trong khung de phan chia ngay / thang / nam */
    gotoxy(30, 10);
    printf("%c", 194);
    gotoxy(30, 11);
    printf("%c", 179);
    gotoxy(30, 12);
    printf("%c", 193);
    gotoxy(40, 10);
    printf("%c", 194);
    gotoxy(40, 11);
    printf("%c", 179);
    gotoxy(40, 12);
    printf("%c", 193);
    SetTextColor(7);

    /*---------------------------------------*/
    SetTextColor(LIGHTGREEN);
    gotoxy(28, 1);
    cout << title;
    // SetTextColor(6);
    gotoxy(0, 3);
    cout << "NHAP MA SINH VIEN   ";
    gotoxy(0, 5);
    cout << "NHAP TEN SINH VIEN  ";
    gotoxy(0, 7);
    cout << "NHAP TEN LOP        ";
    gotoxy(0, 9);
    cout << "NHAP DIEM TRUNG BINH";
    gotoxy(0, 11);
    cout << "NHAP NGAY SINH      ";
    // SetTextColor(7);
}

// Vẽ giao diện và in thông tin sinh viên s ra giao diện (Xóa SV theo mã)
void showNode(Student s)
{
    system("cls");
    drawInputMenu("THONG TIN SINH VIEN");
    char className[20], studentCode[20], name[30];
    int day = -1, month = -1, year = -1;
    double averagePoint = -1;
    SetTextColor(11);
    int v1;
    Student temp;

    strcpy(studentCode, s.getstudentCode());
    strcpy(name, s.getname());
    strcpy(className, s.getclassName());
    averagePoint = s.getdiemtb();

    day = s.getDay();
    month = s.getMonth();
    year = s.getYear();
    gotoxy(22, 3);
    cout << studentCode;

    gotoxy(22, 5);
    puts(name);

    gotoxy(50, 5);
    SetTextColor(8);
    cout << char(179);
    SetTextColor(11);

    //in ten lop ra bang nhap
    gotoxy(22, 7);
    cout << className;

    gotoxy(22, 9);
    cout << averagePoint;

    gotoxy(22, 11);
    cout << day;

    gotoxy(32, 11);
    cout << month;

    gotoxy(42, 11);
    cout << year;
}

//Vẽ bảng danh sách sinh viên
void drawing_frame(int Size)
{
    // 200 : goc duoi ben trai
    // 188 : goc duoi ben phai
    // 201 : goc tren ben trai
    // 187 : goc tren ben phai
    // 205 : duong ngang kep
    // 186 : duong goc kep
    // int Size = 5;
    /** Ve khung cho "DANH SACH SINH VIEN" *******************/
    SetTextColor(8);
    gotoxy(38, 0);
    printf("%c", 218);
    for (int i = 0; i < 42; i++)
        printf("%c", 196);
    printf("%c\n", 191);
    gotoxy(38, 1);
    printf("%c%42c\n", 179, 179);
    gotoxy(38, 1);
    printf("%c", 195);
    for (int i = 0; i < 42; i++)
        printf("%c", 196);
    gotoxy(38, 1);
    printf("%c%43c\n", 179, 179);
    gotoxy(38, 2);
    printf("%c", 192);
    for (int i = 0; i < 42; i++)
        printf("%c", 196);
    printf("%c", 217);
    SetTextColor(7);
    /*********************************************************/

    gotoxy(103, 2);
    cout << "(ESC) Exit";
    SetTextColor(14);
    gotoxy(51, 1);
    cout << "DANH SACH SINH VIEN";
    SetTextColor(7);

    /** Ve khung kep ben ngoai**********************************************/
    SetTextColor(8);
    gotoxy(5, 3);
    printf("%c", 201);
    for (int i = 1; i < 108; i++)
        cout << char(205);
    printf("%c\n", 187);

    for (int i = 4; i < 5 + 2 * Size; i++)
    {
        gotoxy(5, i);
        printf("%c%108c\n", 186, 186);
    }

    gotoxy(5, 5 + 2 * Size);
    printf("%c", 200);
    for (int i = 1; i < 108; i++)
        cout << char(205);
    printf("%c\n", 188);
    /***********************************************************************/

    /** ve khung ghi cac loai thong tin *************************************/
    gotoxy(5, 5);
    printf("%c", 204);
    for (int i = 1; i < 108; i++)
        cout << char(205);
    printf("%c\n", 185);
    gotoxy(20, 3);
    cout << char(203);
    gotoxy(38, 3);
    cout << char(203);
    gotoxy(68, 3);
    cout << char(203);
    gotoxy(93, 3);
    cout << char(203);
    gotoxy(20, 4);
    printf("%c%18c%30c%25c", 186, 186, 186, 186); // cout << char(186);
    gotoxy(20, 5);
    cout << char(202);
    gotoxy(38, 5);
    cout << char(202);
    gotoxy(68, 5);
    cout << char(202);
    gotoxy(93, 5);
    cout << char(202);

    SetTextColor(14);
    gotoxy(7, 4);
    cout << "MA SINH VIEN";
    gotoxy(26, 4);
    cout << "MA LOP";
    gotoxy(47, 4);
    cout << "TEN SINH VIEN";
    gotoxy(96, 4);
    cout << "DIEM TRUNG BINH";
    gotoxy(76, 4);
    cout << "NGAY SINH";
    SetTextColor(7);
    /********************************************************************/

    /** Ve khung don ben trong ******************************************/
    SetTextColor(8);
    int row = 7;
    /* ve cac dong ngang don trong khung */
    for (int i = 1; i < Size; i++)
    {
        gotoxy(5, row);
        cout << char(199);
        for (int i = 1; i < 108; i++)
            printf("%c", 196);
        cout << char(182);
        row = row + 2;
    }
    /* Ve cac duong doc don trong khung */
    row = 6;
    for (int i = 1; i <= Size; i++)
    {
        gotoxy(20, row);
        printf("%c%18c%30c%25c", 179, 179, 179, 179);
        row = row + 1;
        gotoxy(20, row);
        cout << char(197);
        gotoxy(38, row);
        cout << char(197);
        gotoxy(68, row);
        cout << char(197);
        gotoxy(93, row);
        cout << char(197);
        row = row + 1;
    }
    row = row - 1;
    gotoxy(20, row);
    cout << char(207);
    gotoxy(38, row);
    cout << char(207);
    gotoxy(68, row);
    cout << char(207);
    gotoxy(93, row);
    cout << char(207);
    SetTextColor(7);
    /************************************************************************/
}


//Vẽ đối tượng ô chữ nhật với các tham số kích thước, vị trí
void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
    SetTextColor(b_color);
    for (int iy = y + 1; iy <= y + h - 1; iy++)
    {
        for (int ix = x + 1; ix <= x + w - 1; ix++)
        {
            gotoxy(ix, iy);
            cout << " ";
        }
    }
    SetColor(7);
    gotoxy(x + 1, y + 1);
    cout << nd;

    //==========ve vien=========
    SetTextColor(1);
    SetColor(t_color);
    if (h <= 1 || w <= 1)
    {
        // trong o phai co dong o giua
        return;
    }

    // chieu dai
    for (int ix = x; ix <= x + w; ix++)
    {
        gotoxy(ix, y);
        cout << char(196); // ma ascii
        gotoxy(ix, y + h);
        cout << char(196);
    }

    // chieu rong
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoxy(x, iy);
        cout << char(179); // ma ascii
        gotoxy(x + w, iy);
        cout << char(179);
    }

    // sua cac goc
    gotoxy(x, y);
    cout << char(218);
    gotoxy(x + w, y);
    cout << char(191);
    gotoxy(x, y + h);
    cout << char(192);
    gotoxy(x + w, y + h);
    cout << char(217);
}

void delbox(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	int len = nd.length();
    gotoxy(x + 1, y + 1);
	for(int i = 0 ; i< len;i++){
		cout << " ";
	}

    //==========xoa vien=========

    if (h <= 1 || w <= 1)
    {
        // trong o phai co dong o giua
        return;
    }

    // chieu dai
    for (int ix = x; ix <= x + w; ix++)
    {
        gotoxy(ix, y);
        cout << " "; 
        gotoxy(ix, y + h);
        cout << " ";
    }

    // chieu rong
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoxy(x, iy);
        cout << " "; 
        gotoxy(x + w, iy);
        cout << " ";
    }

    // sua cac goc
    gotoxy(x, y);
    cout << " ";
    gotoxy(x + w, y);
    cout << " ";
    gotoxy(x, y + h);
    cout << " ";
    gotoxy(x + w, y + h);
    cout << " ";
}

#endif

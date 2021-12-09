/*******************************************************/
/** Nhập xuất danh sách sinh viên qua màn hình console**/
/*******************************************************/
#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <limits>
#include <math.h>
#include "rlutil.h"
#include "LinkedList.h"

using namespace std;
// Mau
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

typedef LinkedList Student_list;

int breaknow = 0;

// get key on keyboard
int key()
{
    fflush(stdin);
    char c = getch();
    if ((int)c == -32)
        c = getch();
    switch ((int)c)
    {
    case 27:
        return 2; // Nut ESC thoat
    case 13:
        return 1; // Nut Enter
    case 75:
        return 3; // Qua trai
    case 77:
        return 4; // Qua phai
    default:
        return 0; // Others;
    }
}

const int MAX_VALID_YR = 2010;
const int MIN_VALID_YR = 1950;

/*** Check day is valid or not********************************/
// Returns true if
// given year is valid.
bool isLeap(int year)
{

    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

// Returns true if given
// year is valid or not.
bool isValidDate(int d, int m, int y)
{
    // If year, month and day
    // are not in given range
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    // Handle February month
    // with leap year
    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    // Months of April, June,
    // Sept and Nov must have
    // number of days less than
    // or equal to 30.
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}
/************************************************************/

/*Tuper Name (xoa trang dau cuoi, viet hoa chu dau) return a touped char**/
char *touper(char *a)
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
void displayStudentList(Student_list student_list);
/*** start INPUT ********************************************/
/*Drawing a frame to enter Student */
void drawInputMenu()
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
    printf("%c%30c\n", 122, 122);
    // hang 2
    gotoxy(20, 4);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 5);
    printf("%c%30c\n", 122, 122);
    // hang 4
    gotoxy(20, 6);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 7);
    printf("%c%30c\n", 122, 122);
    // hang 6
    gotoxy(20, 8);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 9);
    printf("%c%30c\n", 122, 122);
    // hang 8
    gotoxy(20, 10);
    printf("%c", 195);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c\n", 180);
    gotoxy(20, 11);
    printf("%c%30c\n", 122, 122);
    // hang cuoi
    gotoxy(20, 12);
    printf("%c", 192);
    for (int i = 0; i < 29; i++)
        printf("%c", 196);
    printf("%c", 217);

    /* Neu muon ve rieng mot khung thi dung code nay */
    /*gotoxy(20,14); printf("%c",218);	for(int i=0;i<29;i++)	printf("%c",196); printf("%c\n",191);	gotoxy(20,15);printf("%c%30c\n",122,122);
    gotoxy(20,15);printf("%c",195);	for(int i=0;i<29;i++)	printf("%c",196); printf("%c\n",180);	gotoxy(20,15);printf("%c%30c\n",122,122);
    gotoxy(20,16);printf("%c",192); for(int i=0;i<29;i++)   printf("%c",196); printf("%c",217);*/
    /*-----------------------------------------------*/

    /* Ve hai duong doc trong khung de phan chia ngay / thang / nam */
    gotoxy(30, 10);
    printf("%c", 194);
    gotoxy(30, 11);
    printf("%c", 122);
    gotoxy(30, 12);
    printf("%c", 193);
    gotoxy(40, 10);
    printf("%c", 194);
    gotoxy(40, 11);
    printf("%c", 122);
    gotoxy(40, 12);
    printf("%c", 193);
    SetTextColor(7);

    /*---------------------------------------*/
    SetTextColor(LIGHTGREEN);
    gotoxy(28, 1);
    cout << "THEM SINH VIEN";
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
    cout << "NHAP NGAY SINH     ";
    // SetTextColor(7);

}

/* Kiem tra du lieu sinh vien va chuan hoa */
bool checkData(Student &st)
{

    /* Kiem tru du lieu nhap vao*/
    bool value = true;
    gotoxy(0, 15);
    if (!strlen(st.getname()) || !strlen(st.getclassName()) || !strlen(st.getstudentCode()))
    {
        value = false;
    }
    // Kiem tra ngay sinh nhap vao
    if (!isValidDate(st.getDay(), st.getMonth(), st.getYear()))
    {
        cout << "Error:  Ngay sinh khong hop le!         \n";
        value = false;
    }
    // Kiem tra ma sinh vien (khong can thiet vi da kiem tra ngay tai phan nhap sv)
    if (strlen(st.getstudentCode()) != 8)
    {
        cout << "Error:  Ma sinh vien khong hop le!       \n";
        value = false;
    }
    /*Chuan hoa du lieu */
    // chuan hoa ten
    if (value)
    {
        st.chuanhoa();
    }

    return value;
}


/* Nhap va tra ve 1 sinh vien (chua kiem tra hop le hay khong) */
Student InputStudent()
{
    system("cls");
    drawInputMenu();
    char className[20], studentCode[20], name[30];
    int day = -1, month = -1, year = -1;
    double averagePoint = -1;
    SetTextColor(11);
    int v1;
    Student temp;
    while (true)
    {
        fflush(stdin);
        gotoxy(0, 15);
        cout << "\nSan sang nhap ? ENTER\t||\tThoat: ESC\t";
        v1 = key(); // 1 : enter, 2 : esc, 0 : others
        if (v1 == 2)
        {
            breaknow = 1;
            break;
        }
        if (v1 == 1)
        {
            breaknow = 0;
            break;
        }
    }
    if (v1 == 2)
        return temp;

    fflush(stdin);
    do
    {
        gotoxy(22, 3);
        cout << "                 ";
        gotoxy(22, 3);
        fgets(studentCode, 25, stdin);
        strtok(studentCode, "\n");
        if (strlen(studentCode) != 8)
        {
            gotoxy(0, 15);
            cout << "Error: Ma sinh vien khong hop le!(Ma sinh vien gom 8 ki tu)\n";
        }
    } while (strlen(studentCode) != 8);
    gotoxy(0, 15);
    cout << "                                     "; // xoa dong error

    // nhap ten va chuan hoa ten
    gotoxy(22, 5);
    fgets(name, 25, stdin);
    strtok(name, "\n"); // getline(cin,name);
    strcpy(name, touper(name));
    gotoxy(22, 5);
    // In lai ten da nhap
    puts(name);
    gotoxy(50, 5);
    SetTextColor(8);
    cout << char(122);
    SetTextColor(11);

    // tiep tuc nhap
    gotoxy(22, 7);
    fgets(className, 25, stdin);
    strtok(className, "\n");
    fflush(stdin); // getline(cin,className);

    do
    {
        gotoxy(22, 9);
        cout << "                ";
        gotoxy(22, 9);
        cin >> averagePoint;
        if (cin.fail())
        {
            gotoxy(0, 15);
            cout << "Error: Nhap sai kieu du lieu!\n";
            cin.clear();
            cin.ignore(256, '\n');
            averagePoint = -1;
        }
        else
        {
            gotoxy(0, 15);
            cout << "                                     \n";
        }
    } while (averagePoint < 0 || averagePoint > 10);

    fflush(stdin);
    do
    {
        gotoxy(22, 11);
        cout << "        ";
        gotoxy(22, 11);
        cin >> day;
        if (cin.fail())
        {
            gotoxy(0, 15);
            cout << "Error: Nhap sai kieu du lieu!\n";
            cin.clear();
            cin.ignore(256, '\n');
            day = -1;
        }
        else
        {
            gotoxy(0, 15);
            cout << "                                     \n";
        }
    } while (day < 0);

    do
    {
        gotoxy(32, 11);
        cout << "       ";
        gotoxy(32, 11);
        cin >> month;
        if (cin.fail())
        {
            gotoxy(0, 15);
            cout << "Error: Nhap sai kieu du lieu!\n";
            cin.clear();
            cin.ignore(256, '\n');
            month = -1;
        }
        else
        {
            gotoxy(0, 15);
            cout << "                                     \n";
        }
    } while (month < 0);

    do
    {
        gotoxy(42, 11);
        cout << "        ";
        gotoxy(42, 11);
        cin >> year;
        if (cin.fail())
        {
            gotoxy(0, 15);
            cout << "Error: Nhap sai kieu du lieu!\n";
            cin.clear();
            cin.ignore(256, '\n');
            year = -1;
        }
        else
        {
            gotoxy(0, 15);
            cout << "                                     \n";
        }
    } while (year < 0);
    // gotoxy(22,11); cin >> day;
    // gotoxy(32,11); cin >> month;
    // gotoxy(42,11); cin >> year;
    SetTextColor(7);
    Student st(className, studentCode, name, day, month, year, averagePoint);
    return st;
}

/* Enter a list of Student */
void enter(Student_list &student_list)
{
    // Student_list student_list;
    while (true)
    {
        // Nhap du 1 lieu sinh vien
        Student st = InputStudent();
        if (!breaknow)
        {
            // kiem tra sinh vien hop le
            if (checkData(st))
            {
                student_list.push_back(st);
                cout << "Status: Add student successful!\n";
            }
            else
                cout << "Status: Add student failed!\n";

            cout << "\nTiep tuc nhap: ENTER\t||\tThoat: ESC\t";
            int x;
            while (true)
            {
                fflush(stdin);
                x = key(); // 1 : enter, 2 : esc, 0 : others
                if (x == 1 || x == 2)
                    break;
            }
            if (x == 2)
                break;
        }
        else
        {
            break;
        }
        // Tiep tuc nhap hoac thoat
    }
    // system("cls");
    // return student_list;
}

/**** end INPUT ***********************************************/

/*** star OUTPUT **********************************************/
/*Ve Khung de hien thi cac thong tin sinh vien*/
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
    printf("%c%42c\n", 122, 122);
    gotoxy(38, 1);
    printf("%c", 195);
    for (int i = 0; i < 42; i++)
        printf("%c", 196);
    gotoxy(38, 1);
    printf("%c%43c\n", 122, 122);
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
        printf("%c%18c%30c%25c", 122, 122, 122, 122);
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

    // gotoxy(0,20);
    // for (int i = 100 ; i < 255; i++) cout << i << ":" << char(i) << "\t\t";
}

/* Ghi thong tin cac sinh vien vao khung */
void show(Student_list &student_list)
{
    // system("cls");
    SetTextColor(7);
    // Ve khung theo so luong sinh vien
    drawing_frame(student_list.getN());
    Student st;
    int row = 6;
    int Size = student_list.getN();
    // In thong tin tung sinh vien
    for (int i = 0; i < Size; i++)
    {
        st = *student_list.at(i);
        gotoxy(9, row);
        cout << st.getstudentCode();
        gotoxy(26, row);
        cout << st.getclassName();
        gotoxy(42, row);
        cout << st.getname();
        gotoxy(102, row);
        cout << st.getDiemTb();
        // gotoxy(73,row);    printf("%d / %d / %d", st.getDay(), st.getMonth(), st.getYear());
        /* In ngay thang nam chuan hoa */
        gotoxy(74, row);
        if (st.getDay() < 10)
            cout << "0" << st.getDay() << " / ";
        else
            cout << st.getDay() << " / ";
        if (st.getMonth() < 3)
            cout << "0" << st.getMonth() << " / ";
        else if (st.getMonth() < 10)
            cout << " " << st.getMonth() << " / ";
        else
            cout << st.getMonth() << " / ";
        cout << st.getYear();
        row = row + 2;
    }
   
}

// display list student to console, using <- and -> to see previous or next table
void displayStudentList(Student_list student_list)
{
    int x, Size = student_list.getN();
    int beginPos = 0, endPos = min(beginPos + 9, Size - 1); // beginPos+15 < Size ? beginPos+15 : Size;
    Student_list List;
    while (true)
    {
        if (x != 0 && x != 1)
        {
            system("cls");
            // create a small list student to display in small table
            List.clear();
            endPos = min(beginPos + 9, Size - 1);
            for (int i = beginPos; i <= endPos; i++)
                List.push_back(student_list[i]);
            gotoxy(6, 2);
            cout << "Total: " << Size;
            // In danh sach
            show(List);
        }
        fflush(stdin);
        x = key(); // 1 : enter, 2 : esc, 0 : others
        if (x == 2)
            break; //  Bam ESC
        if (x == 4)
        { // qua phai
            if (endPos == Size - 1)
            {
                x = 0;
                continue;
            }
            beginPos = min(beginPos + 10, Size - 1);
            // endPos = min(beginPos+9, Size-1);
        }
        if (x == 3)
        { // qua trai
            if (beginPos == 0)
            {
                x = 0;
                continue;
            }
            beginPos = max(beginPos - 10, 0);
            // endPos = min(beginPos+9, Size - 1);
        }
    }
    system("cls");
   
}

/**** end OUTPUT ***********************************************/

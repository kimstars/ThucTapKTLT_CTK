
void EditStudent(Student &s)
{
    system("cls");
    drawInputMenu();
    char className[20], studentCode[20], name[30];
    int day = -1, month = -1, year = -1;
    double averagePoint = -1;
    SetTextColor(11);
    int v1;
    Student temp;
    
    

    fflush(stdin);
    do
    {
        gotoxy(22, 3);
        cout << s.getstudentCode();
        strcpy(studentCode,s.getstudentCode());
        // gotoxy(22, 3);
        showcursor();
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
    cout << s.getname();
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
    cout << s.getclassName();
    fgets(className, 25, stdin);
    strtok(className, "\n");
    fflush(stdin); // getline(cin,className);

    do
    {
        gotoxy(22, 9);
        cout << "                ";
        cout << s.getdiemtb();
        // gotoxy(22, 9);
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
        cout << s.getDay();
        // gotoxy(22, 11);
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
        cout << s.getMonth();
        // gotoxy(32, 11);
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
        cout << s.getYear();
        // gotoxy(42, 11);
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
    s = st;
}



void InputEdit(Student &s) {

    system("cls");
    drawInputMenu();
    char className[20], studentCode[20], name[30];
    int day = -1, month = -1, year = -1;
    double averagePoint = -1;
    SetTextColor(11);
    int v1;


    

    int numOfLabel = 1;
    int positionOfCursor = 22;
    INPUT_RECORD ir[128];
	HANDLE hStdInput;
    DWORD nRead;
    UINT i;
    SHORT X, Y;
    int location, precedeLocation = 0;
    hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdInput, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT);
    FlushConsoleInputBuffer(hStdInput);
    showcursor();
    // gotoxy(22, 23);
    // printf("\u001b[48;5;231m\u001b[38;5;240m  /  /    ");
    gotoxy(22 + strlen(studentCode), 3 + numOfLabel * 2);

    while (1) {
        ReadConsoleInput(hStdInput, ir, 128, &nRead);
        for(i = 0; i < nRead; i++) {
            if (ir[i].EventType == KEY_EVENT && ir[i].Event.KeyEvent.bKeyDown) {
                switch (ir[i].Event.KeyEvent.wVirtualKeyCode) {
                    case VK_LEFT:
                        if (positionOfCursor > 22) {
                            positionOfCursor--;
                            gotoxy(positionOfCursor, 3 + numOfLabel * 2);
                        }
                        break;
                    case VK_RIGHT:
                        if (positionOfCursor < 22 + strlen(buf[numOfLabel - 1])) {
                            positionOfCursor++;
                            gotoxy(positionOfCursor, 3 + numOfLabel * 2);
                        }
                        break;
                    case VK_DOWN:
                        if (numOfLabel <= 4) {
                            numOfLabel++;
                            positionOfCursor = 22 + strlen(buf[numOfLabel - 1]);
                            gotoxy(positionOfCursor, 3 + numOfLabel * 2);
                        } 
                        break;
                    case VK_UP:
                        if (numOfLabel >= 2) {
                            numOfLabel--;
                            positionOfCursor = 22 + strlen(buf[numOfLabel - 1]);
                            gotoxy(positionOfCursor, 3 + numOfLabel * 2);
                        } 
                        break;
                    case VK_BACK:
                        if (strlen(buf[numOfLabel - 1]) > 0 && positionOfCursor != 22) {
                            if (numOfLabel == 3) {
                                if (positionOfCursor == 82 || positionOfCursor == 85) {
                                    positionOfCursor--;
                                }
                                positionOfCursor--;
                                className[positionOfCursor - 22] = ' ';
                                gotoxy(22, 23);
                                printf("\u001b[48;5;231m\u001b[38;5;240m%s ", className);
                                gotoxy(positionOfCursor, 23);
                                continue;
                            }
                            backspace(buf[numOfLabel - 1], positionOfCursor - 80);
                            gotoxy(22, 3 + numOfLabel * 2);
                            printf("\u001b[48;5;231m\u001b[38;5;240m%s ", buf[numOfLabel - 1]);
                            positionOfCursor--;
                        }
                        break;
                }
                CHAR input = ir[i].Event.KeyEvent.uChar.AsciiChar;
                if (strlen(buf[numOfLabel - 1]) < 30) {
                    if ((input >= 65 && input<= 90) || (input >= 97 && input<= 122) || (input >= 48 && input <= 57) || input == 32) {
                        if (numOfLabel == 3) {
                            if (positionOfCursor == 89) {
                                continue;
                            }
                            if (input >= 48 && input <= 57) {
                                className[positionOfCursor - 22] = input;
                                gotoxy(22, 23);
                                printf("\u001b[48;5;231m\u001b[38;5;240m%s", className);
                                if (positionOfCursor == 80 || positionOfCursor == 83) {
                                    positionOfCursor++;
                                }
                                positionOfCursor++;
                                gotoxy(positionOfCursor, 23);
                            }
                            continue;
                        }
                        char insert[2] = {input, '\0'};
                        append(buf[numOfLabel - 1], insert, positionOfCursor - 22);
                        gotoxy(22, 3 + numOfLabel * 2);
                        printf("\u001b[48;5;231m\u001b[38;5;240m%s", buf[numOfLabel - 1]);
                        positionOfCursor++;
                    }
                }
                gotoxy(positionOfCursor, 3 + numOfLabel * 2);
            }
        }
    }
}


void Edit(Student_list &student_list, int i){  
    Student a = student_list[i];
    InputEdit(a);
    displayStudentList(student_list);

}
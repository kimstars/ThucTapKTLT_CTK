#include "Student.h"
#include <fstream>

#ifndef list
#define list
class LinkedList
{
private:
    Student *head;
    int n;

public:
    LinkedList()
    {
        head = NULL;
        n = 0;
    }
    ~LinkedList(){};

    void push_back(Student a);
    void printList();

    void read(string filename);
    void write(string filename);

    Student *at(int i);
    Student operator[](int i);
    void operator=(LinkedList f);

    int getN() { return n; }

    void swap(Student *a, Student *b);
    void clear();

    void DeleteAt(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        Student *temp = head;
        if (pos == 0)
        {
            head = temp->next;
            free(temp);
            return;
        }

        for (int i = 0; temp != NULL && i < pos - 1; i++)
            temp = temp->next;
        if (temp == NULL || temp->next == NULL)
            return;

        Student *next = temp->next->next;
        free(temp->next); // Free memory
        temp->next = next;
    }
};

void LinkedList::clear()
{
    n = 0;
    head = NULL;
}
void LinkedList::operator=(LinkedList f)
{
    n = f.getN();
    head = f.at(0);
}

void LinkedList::swap(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// trả về con trỏ student
Student *LinkedList::at(int i)
{
    int count = 0;
    Student *temp = head;
    while (count < i)
    {
        temp = temp->next;
        ++count;
    }
    return temp;
}

// trả về đối tượng student
Student LinkedList::operator[](int i)
{
    if (i >= 0 && i <= n)
    {
        Student *temp = head;
        while (i--)
        {
            temp = temp->next;
        }
        return *temp;
    }
}

// thêm vào danh sách liên kết
void LinkedList::push_back(Student a)
{
    Student *new_Student = new Student;
    (*new_Student) = a;
    if (head == NULL)
    {
        head = new_Student;
        n++;
        return;
    }
    Student *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_Student;
    n++;
    // cout << n << " " << *temp;
    // cout << "n = "<< n <<endl;
    // new_Student->next = NULL;
}

void LinkedList::printList()
{
    Student *Student = head;
    int i = 0;
    while (Student != NULL)
    {
        cout << i << " : ";
        cout << *Student;
        i++;
        Student = Student->next;
    }
    printf("\n");
}

void LinkedList::read(string filename)
{
    fstream fin;
    fin.open(filename, ios::in | ios::binary);
    if (fin.good())
    {
        int sz = 0;
        fin.read((char *)(&sz), sizeof(sz));
        // cout << "read n = "<< n << "sz = " << sz << endl;
        for (int i = 0; i < sz; ++i)
        {
            Student a;
            fin.read((char *)(&a), sizeof(a));
            a.chuanhoa();
            push_back(a);
        }
    }
    else
    {
        cout << "error open file \n";
    }
    fin.close();
    gotoxy(3, 36);
    SetTextColor(GREEN);
    cout << "\nRead successful !\n";
}

void LinkedList::write(string filename)
{
    ofstream fout;
    fout.open(filename, ios::out | ios::binary);
    if (fout.good())
    {
        // fout.seekp(0, ios::beg);
        fout.write((char *)(&n), sizeof(n));
        // cout << "write n = "<< n ;
        Student *temp = head;
        // fout.seekp(0, ios::end);

        for (int i = 0; i < n; i++)
        {
            // Pull the data out of the pointer here.
            // At this point, temp should not be NULL.
            Student temp2 = *(temp);
            fout.write((const char *)(&temp2), sizeof(temp2));
            temp = temp->next;
        }
    }
    fout.close();
    cout << "\nWrite successful !\n";
}

#endif
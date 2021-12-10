#pragma once
#include "Student.h"
#include "Sort.h"

#include <fstream>

struct Node
{
    Student data;
    Node *left;
    Node *right;
};

#ifndef tree
#define tree
class BSTtree
{
public:
    Node *root;
    string type;
    int n;

public:
    BSTtree()
    {
        root = NULL;
        type = "StudentCode";
        n = 0;
    }

    ~BSTtree(){};

    int LeftOf(Student *value, Node *root, string type)
    {
        return compare(type, value, &root->data) == -1;
    }
    int RightOf(Student *value, Node *root, string type)
    {
        return compare(type, value, &root->data) != -1;
    }

    Node *Insert(Node *root, Student *value, string type)
    {
        if (root == NULL)
        {
            Node *node = new Node;
            Student temp;
            node->left = NULL;
            node->right = NULL;
            node->data = *value;
            n++;
            return node;
        }
        if (LeftOf(value, root, type))
            root->left = Insert(root->left, value, type);
        else if (RightOf(value, root, type))
            root->right = Insert(root->right, value, type);
        return root;
    }

    Student Search(Node *root, Student *value, string type)
    {
        Student temp;
        if (root == NULL)
            return temp;
        if (compareBST(type, &root->data, value))
        {
            return root->data;
        }
        else if (LeftOf(value, root, type))
        {
            return Search(root->left, value, type);
        }
        else if (RightOf(value, root, type))
        {
            return Search(root->right, value, type);
        }
    }

    void PreOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << (root->data);
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }

    void readFile(string filename, string type)
    {
        fstream fin;
        fin.open(filename, ios::in | ios::binary);
        if (fin.good())
        {
            int sz = 0;
            fin.read((char *)(&sz), sizeof(sz));
            for (int i = 0; i < sz; ++i)
            {
                Student a;
                fin.read((char *)(&a), sizeof(a));
                a.chuanhoa();
                // cout << a;
                root = Insert(root, &a ,type);
            }
            gotoxy(3, 36);
            SetTextColor(GREEN);
            cout << "\nRead successful !\n";
        }
        else
        {
            cout << "error open file \n";
        }
        fin.close();
        
    }
};

#endif

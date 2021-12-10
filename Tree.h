#include "Student.h"
#include "condition.h"

#include <fstream>


#ifndef Tree
#define Tree

struct Node
{
    Student data;
    Node *left;
    Node *right;
};

class Tree
{
private:
    Node *root;
    string type;

public:
    Tree(){
        root = NULL;
        type = "StudentCode";
    }
    
    ~Tree(){};

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
            node->data = temp;
            return node;
        }
        if (LeftOf(value, root, type))
            root->left = Insert(root->left, value, type);
        else if (RightOf(value, root, type))
            root->right = Insert(root->right, value, type);
        return root;
    }

    bool Search(Node *root, Student *value, string type)
    {
        if (root == NULL)
            return false;
        if (compare(type, &root->data, value))
        {
            return true;
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
            printf("%d ", root->data);
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
};

#endif

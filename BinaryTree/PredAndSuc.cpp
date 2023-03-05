#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *insertInBST(node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertInBST(root->right, data);
    }
    else
    {
        root->left = insertInBST(root->left, data);
    }
    return root;
}
void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
}

void findPreSuc(node *root, node *&pred, node *&succ, int key)
{

    if (root == NULL)
    {
        return;
    }

    // first case key is equal to root->data
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pred = temp;
        }
        if (root->right != NULL)
        {
            node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            succ = temp;
        }

        return;
    }

    if (root->data > key)
    {
        succ = root;
        findPreSuc(root->left, pred, succ, key);
    }
    else
    {
        pred = root;
        findPreSuc(root->right, pred, succ, key);
    }
}
int32_t main()
{

    node *root = NULL;
    cout << "Enter the data to create BST" << endl;
    takeInput(root);
    int key = 70;
    node *pred = NULL;
    node *succ = NULL;
    findPreSuc(root, pred, succ, key);
    if (pred != NULL)
        cout << "Predecessor is " << pred->data << endl;
    else
        cout << "No Predecessor";

    if (succ != NULL)
        cout << "Successor is " << succ->data;
    else
        cout << "No Successor";
}
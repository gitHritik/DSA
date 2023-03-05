#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertInBST(Node *&root, int &data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }

    return root;
}
void createBST(Node *&root)
{
    int data;
    cout << "Enter the data to enter" << endl;
    cin >> data;

    while (data != -1)
    {
        insertInBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrderTravesal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
void inorderPredAndSucc(Node *root, Node *&succ, Node *&pred, int x)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == x)
    {

        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pred = temp;
        }
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            succ = temp;
        }
        return;
    }

    if (root->data > x)
    {
        succ = root;
        inorderPredAndSucc(root->left, succ, pred, x);
    }
    else
    {
        pred = root;
        inorderPredAndSucc(root->right, succ, pred, x);
    }
}

int32_t main()
{

    Node *root = NULL;

    createBST(root);
    Node *succ = NULL;
    Node *pred = NULL;
    int x = 70;
    inorder(root);
    cout << endl;
    levelOrderTravesal(root);

    inorderPredAndSucc(root, succ, pred, x);

    if (pred != NULL)
        cout << "Predecessor is " << pred->data << endl;
    else
        cout << "No Predecessor";

    if (succ != NULL)
        cout << "Successor is " << succ->data;
    else
        cout << "No Successor";
}

// 50 20 70 10 30 90 110 -1
// 10 20 30 50 70 90 110
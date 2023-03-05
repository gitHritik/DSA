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
Node *minValue(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *temp = root;

    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}
Node *deletNodeInBST(Node *root, int x)
{

    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deletNodeInBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > x)
    {
        root->left = deletNodeInBST(root->left, x);
        return root;
    }
    else
    {
        root->right = deletNodeInBST(root->right, x);
        return root;
    }
}
int32_t main()
{

    Node *root = NULL;

    createBST(root);

    inorder(root);
    cout << endl;
    levelOrderTravesal(root);

    root = deletNodeInBST(root, 50);
    levelOrderTravesal(root);
}

// 50 20 70 10 30 90 110 -1
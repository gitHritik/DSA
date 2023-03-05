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
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {

                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    postOrder(root->left);
    postOrder(root->right);
}
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}
node *minVal(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }

    return temp;
}
node *maxVal(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }

    return temp;
}

node *deleteFromBST(node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
    }
}
int32_t main()
{
    node *root = NULL;
    cout << "Enter the data to create BST" << endl;
    takeInput(root);
    levelOrderTraversal(root);

    // cout << endl
    //      << "Printing Preorder" << endl;
    // inOrder(root);

    // cout << minVal(root)->data << endl;
    // cout << maxVal(root)->data << endl;
    root = deleteFromBST(root, 50);
    levelOrderTraversal(root);
}

// 10 8 21 7 25 5 4 3 -1
// 50 30 70 20 40 60 80 -1
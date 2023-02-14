#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

void buildTreeWithLOT(node *&root)
{
    queue<node *> q;
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the data to insert in left of :" << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter the data to insert in right of :" << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
node *solve(node *root, int &k, int n)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n)
    {
        return root;
    }

    node *left = solve(root->left, k, n);
    node *right = solve(root->right, k, n);

    if (left != NULL && right == NULL)
    {
        k--;
        while (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if (left == NULL && right != NULL)
    {
        k--;
        while (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

int32_t main()
{
    node *root = NULL;
    buildTreeWithLOT(root);
    int k = 2;
    int n = 4;
    int ans = kthAncestor(root, k, n);

    cout << ans;
}

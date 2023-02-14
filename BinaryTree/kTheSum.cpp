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
void solve(node *root, int k, vector<int> path, int &count)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    solve(root->left, k, path, count);
    solve(root->right, k, path, count);

    int size = path.size();
    int sum = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}
int sumK(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    return count;
}
int32_t main()
{
    node *root = NULL;
    buildTreeWithLOT(root);
    int k = 3;
    int ans = sumK(root, k);

    cout << ans;
}

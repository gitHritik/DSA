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
vector<int> diagonal(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node *> q;

    q.push(root);
    while (!q.empty())
    {
        node *frontNode = q.front();
        q.pop();
        while (frontNode)
        {
            ans.push_back(frontNode->data);
            if (frontNode->left)
                q.push(frontNode->left);
            frontNode = frontNode->right;
        }
    }
    return ans;
}
int32_t main()
{
    node *root = NULL;
    buildTreeWithLOT(root);

    vector<int> ans = diagonal(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}

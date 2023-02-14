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
int createMapping(int in[], int element, int inOrderStart, int inOrderEnd, int n)
{
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    // base case

    if (index >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = pre[index++];

    node *root = new node(element);

    int pos = createMapping(in, element, inOrderStart, inOrderEnd, n);

    root->left = solve(in, pre, index, inOrderStart, pos - 1, n);
    root->right = solve(in, pre, index, pos + 1, inOrderEnd, n);

    return root;
}
node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    // map<int,int> nodeToIndex;

    // createMapping(in,0,n-1,nodeToIndex);

    node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);

    return ans;
}
int32_t main()
{
    node *root = NULL;
    buildTree(root);
}
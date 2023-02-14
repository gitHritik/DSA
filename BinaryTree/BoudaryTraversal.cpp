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

void traverseLeft(node *root, vector<int> &ans)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}
void traverseLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    ans.push_back(root->data);
}
vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // step 1 travese in left
    traverseLeft(root->left, ans);

    // step 2 traverse in leaft
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // ste3 traverse in right

    traverseRight(root->right, ans);

    return ans;
}
int32_t main()
{
    node *root = NULL;
    buildTreeWithLOT(root);
    vector<int> ans = boundary(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}
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

node *buildTree(node *root)
{

    cout << "Enter the data to insert:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data to insert in left of :" << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to insert in right of :" << root->data << endl;
    root->right = buildTree(root->right);

    return root;
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
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
void ReverselevelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    stack<node *> s;
    // q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    while (!s.empty())
    {
        node *temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> s;
    node *curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> s;
    node *curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}
void postOrder(node *root)
{
    stack<node *> s;
    s.push(root);

    stack<int> st;
    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
        st.push(curr->data);
        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int32_t main()
{
    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // levelOrderTraversal(root);
    // ReverselevelOrderTraversal(root);
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        while (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for " << value << endl;
        ;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAttail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtMiddle(Node *&tail, Node *&head, int data, int pos)
{

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    Node *newNode = new Node(data);
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

Node *getMid(Node *head)
{
    // if (head == NULL)
    // {
    //     return head;
    // }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
Node *mergeSort(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // step1 : find mid
    Node *mid = getMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // step2 : recursive call
    left = mergeSort(left);
    right = mergeSort(right);

    // step3: merge both part
    Node *ans = merge(left, right);
    return ans;
}
int32_t main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;

    insertAttail(tail, 4);
    insertAttail(tail, 3);
    insertAttail(tail, 2);
    insertAttail(tail, 9);
    insertAttail(tail, 1);
    print(head);
    Node *ans = mergeSort(head);
    print(ans);
}
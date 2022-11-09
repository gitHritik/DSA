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
        while (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

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
Node *reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}
bool isCircular(Node *head)
{
    if (head == NULL || head->next == head)
    {
        return true;
    }

    if (head->next == NULL)
    {
        return false;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);

    insertAtTail(tail, 4);

    insertAtTail(tail, 5);
    print(head);

    // Node *ans = reverseList(head);
    // print(ans);

    cout << "Head  " << head->data << endl;
    if (isCircular(head))
    {
        cout << "Circular" << endl;
    }
    else
    {
        cout << "Not circular" << endl;
    }
}
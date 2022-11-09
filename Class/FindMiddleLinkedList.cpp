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

void insertAtMiddle(Node *&head, Node *&tail, int pos, int d)
{
    Node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
    tail = newNode;
}
int getLen(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
void getMiddle(Node *head, int len)
{
    int ans = len / 2;
    Node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    cout << temp->data << endl;
}
void getMiddle2(Node *head)
{
    if (head == NULL)
    {
        cout << head << endl;
        return;
    }
    if (head->next == NULL)
    {
        cout << head << endl;
        return;
    }
    if (head->next->next == NULL)
    {
        cout << head->next << endl;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    cout << slow->data << endl;
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
int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    print(head);
    // int len = getLen(head);
    // getMiddle(head, len);
    getMiddle2(head);
}
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

void mergeSortedOnes(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    int oneCount = 0;
    int zeroCount = 0;
    int twoCount = 0;
    Node *temp = head;

    while (temp != NULL)
    {

        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }

        temp = temp->next;
    }
    temp = head;

    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
}

void insertAtTail(Node *&tail, Node *curr)
{

    tail->next = curr;
    tail = curr;
}

Node *mergeOne(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // creation is done
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (curr->data == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (curr->data == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merging

    if (oneHead->next == NULL)
    {
        zeroTail->next = twoHead->next;
    }
    else
    {
        zeroTail->next = oneHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    return zeroHead->next;
}

int32_t main()
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 2);
    insertAttail(tail, 2);
    insertAttail(tail, 1);
    insertAttail(tail, 0);
    insertAttail(tail, 1);
    // insertAtMiddle(tail, head, 4, 6);
    print(head);
    // mergeSortedOnes(head);
    Node *ans = mergeOne(head);
    print(ans);
}
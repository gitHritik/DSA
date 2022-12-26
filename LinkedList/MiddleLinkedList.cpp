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

int middleOfLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 4);
    insertAttail(tail, 5);
    // insertAtMiddle(tail, head, 6, 6);
    print(head);
    int ans = middleOfLinkedList(head);
    cout << ans << endl;
}
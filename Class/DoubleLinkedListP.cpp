#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtMiddle(Node *&head, Node *&tail, int pos, int data)
{
    Node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
}

void deleteNode(Node *&tail, Node *&head, int postion)
{
    Node *temp = head;
    if (postion == 1)
    {
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < postion)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            prev->next = NULL;
            curr->prev = NULL;
            tail = prev;
            return;
        }
        prev->next = curr->next;
        curr->next = prev;
        curr->next = NULL;
        delete curr;
    }
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
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, tail, 3);
    print(head);
    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;

    insertAtTail(head, tail, 1);
    print(head);

    insertAtMiddle(head, tail, 1, 4);
    print(head);
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    deleteNode(tail, head, 2);
    print(head);
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
}
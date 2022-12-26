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

// void insertAtMiddle(Node *&tail, Node *&head, int data, int pos)
// {

//     if (pos == 1)
//     {
//         insertAtHead(head, data);
//         return;
//     }
//     Node *temp = head;
//     int count = 1;
//     Node *newNode = new Node(data);
//     while (count < pos - 1)
//     {
//         temp = temp->next;
//         count++;
//     }
//     if (temp->next == NULL)
//     {
//         insertAttail(tail, data);
//         return;
//     }
//     newNode->next = temp->next;
//     temp->next = newNode;
// }
// Recursion appraoch 2
// Node *reverse(Node *&head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     Node *chotaHead = reverse(head->next);
//     head->next->next = head;
//     head->next = NULL;

//     return chotaHead;
// }

// by recursive manner
// void reverse(Node *&head, Node *curr, Node *prev)
// {
//     if (curr == NULL)
//     {
//         head = prev;
//         return;
//     }
//     Node *forward = curr->next;
//     reverse(head, forward, curr);
//     curr->next = prev;
// }

// By iterative manner
//  void reverse(Node *&head)
//  {
//      if (head == NULL || head->next == NULL)
//      {
//          return;
//      }
//      Node *prev = NULL;
//      Node *forwared = NULL;
//      Node *curr = head;

//     while (curr != NULL)
//     {
//         forwared = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forwared;
//     }

//     head = prev;
// }

int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    Node *prev = NULL;
    Node *curr = head;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 4);
    insertAttail(tail, 5);
    insertAtMiddle(tail, head, 6, 6);
    print(head);
    // reverse(head, curr, prev);
    Node *ans = reverse(head);
    print(ans);
}
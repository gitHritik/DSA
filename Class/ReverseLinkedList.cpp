#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class Node
{

public:
    string name;
    Node *next;

    Node(string name)
    {
        this->name = name;
        this->next = NULL;
    }
    ~Node()
    {
        string value = this->name;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for  " << value << endl;
    }
};

// inserting in start of linked list
void insertAtHead(Node *&head, string name)
{
    Node *temp = new Node(name);
    temp->next = head;
    head = temp;
}

// inserting in end of linked list
void insertAtTail(Node *&tail, string name)
{
    Node *temp = new Node(name);
    tail->next = temp;
    tail = temp;
}

// inserting in middle of linked list

void insertInMiddle(Node *&tail, Node *&head, int pos, string name)
{
    Node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, name);
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, name);
        return;
    }
    Node *newNodeStart = new Node(name);
    newNodeStart->next = temp->next;
    temp->next = newNodeStart;
}
// void reverse(Node *&head)
// {

//     if (head->next == NULL)
//     {
//         cout << head->name << "->";
//         return;
//     }
//     Node *curr = head;
//
//     Node *prev = NULL;
//     Node *forward = NULL;
//     while (curr != NULL)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;

//         head = prev;
//     }
// }
Node *RecursiveReverse(Node *&head)
{

    if (head->next == NULL)
    {
        return head;
    }
    Node *chotaHead = RecursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->name << "->";
        temp = temp->next;
    }
    cout << endl;
}
int32_t main()
{
    Node *node1 = new Node("hritik");
    // cout << node1->name << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, "neha");

    insertAtHead(head, "rishabh");

    insertAtTail(tail, "sudhanshu");
    insertAtTail(tail, "priya");
    print(head);
    Node *chothead = RecursiveReverse(head);
    print(chothead);
}
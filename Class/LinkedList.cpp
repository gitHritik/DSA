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

void deleteAtHead(Node *&tail, Node *&head, int postion)
{
    Node *temp = head;

    // deleting first node of head
    if (postion == 1)
    {
        head = head->next;
        temp->next = NULL;
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
            prev->next = curr->next;
            tail = prev;
            curr->next = NULL;
            delete curr;
        }
        else
        {
            prev->next = curr->next;

            curr->next = NULL;
            delete curr;
        }
    }
}
void print(Node *&head)
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
    print(head);

    // insertAtHead(head, "neha");
    // print(head);
    // insertAtHead(head, "rishabh");
    // print(head);

    insertAtTail(tail, "neha");
    // print(head);
    insertAtTail(tail, "priya");
    // print(head);
    insertInMiddle(tail, head, 4, "love");
    print(head);

    // cout << "Head " << head->name << endl;
    // cout << "Tail " << tail->name << endl;

    deleteAtHead(tail, head, 4);
    print(head);

    cout << "Head " << head->name << endl;
    cout << "Tail " << tail->name << endl;
}
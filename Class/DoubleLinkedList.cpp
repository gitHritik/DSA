#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class Node
{

public:
    string name;
    Node *next;
    Node *prev;

    Node(string name)
    {
        this->name = name;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        string value = name;
        while (next != NULL)
        {
            next = NULL;
            delete next;
        }

        cout << "Memory free for " << name << endl;
    }
};

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

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, string name)
{

    if (head == NULL)
    {
        Node *temp = new Node(name);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(name);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, string name)

{
    if (tail == NULL)
    {
        Node *temp = new Node(name);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(name);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertInMiddle(Node *&tail, Node *&head, int pos, string name)
{
    Node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, tail, name);
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
        insertAtTail(head, tail, name);
        return;
    }
    Node *newNodeStart = new Node(name);
    newNodeStart->next = temp->next;
    temp->next->prev = newNodeStart;
    temp->next = newNodeStart;
    newNodeStart->prev = temp;
}

void deleteAtHead(Node *&tail, Node *&head, int postion)
{
    Node *temp = head;

    // deleting first node of head
    if (postion == 1)
    {
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *curr = head;
        Node *previous = NULL;

        int cnt = 1;
        while (cnt < postion)
        {
            previous = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            curr->prev = NULL;
            previous->next = NULL;
            tail = previous;
            delete curr;
        }
        else
        {

            curr->prev = NULL;
            previous->next = curr->next;
            curr->next = NULL;
            // curr->next->prev = previous;
            delete curr;
        }
    }
}

int32_t main()
{
    // Node *node1 = new Node("hritik");
    Node *head = NULL;
    Node *tail = NULL;
    cout << getLength(head) << endl;
    print(head);

    insertAtHead(head, tail, "neha");
    print(head);

    insertAtTail(head, tail, "priyansh");
    print(head);

    // cout << "Head " << head->name << endl;
    // cout << "Tail " << tail->name << endl;

    insertInMiddle(tail, head, 2, "priya");
    print(head);

    insertInMiddle(tail, head, 1, "priyank");
    print(head);
    insertInMiddle(tail, head, 5, "priyanka");
    print(head);

    deleteAtHead(tail, head, 2);
    print(head);
    cout << "Head " << head->name << endl;
    cout << "Tail " << tail->name << endl;
}
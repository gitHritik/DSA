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

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete nodeToDelete;
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);

    insertAtTail(tail, 4);
    insertAtTail(tail, 4);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    print(head);
    Node *ans = removeDuplicates(head);
    print(ans);
}
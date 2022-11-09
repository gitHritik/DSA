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

Node *kReverse(Node *&head, int k)
{

    // base case
    if (head == NULL)
    {
        return NULL;
    }

    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    // Reverse the first k nodes
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Reverse the other nodes
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    // return the head

    return prev;
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
    print(head);
    cout << "head" << head->data << endl;
    Node *ans = kReverse(head, 2);
    cout << "head" << ans->data << endl;
    print(ans);
}
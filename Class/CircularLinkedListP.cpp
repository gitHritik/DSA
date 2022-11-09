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

void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        if (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool isCircular(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        return true;
    }

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return false;
    }

    return true;
}

void print(Node *tail)
{
    Node *curr = tail;
    if (tail == NULL)
    {
        cout << "List is empty";
    }
    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != curr);
    cout << endl;
}
int32_t main()
{
    Node *tail = NULL;
    insertNode(tail, 2, 1);
    print(tail);
    insertNode(tail, 1, 2);
    print(tail);
    insertNode(tail, 2, 4);
    print(tail);
    insertNode(tail, 2, 3);

    print(tail);

    if (isCircular(tail))
    {
        cout << "Linked List is circular";
    }
    else
    {
        cout << "Linked List is not ciruclar";
    }
}
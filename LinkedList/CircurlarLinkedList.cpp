#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
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
int32_t main()
{
    Node *tail = NULL;
    insertNode(tail, 4, 5);
    print(tail);
    // insertNode(tail, 5, 9);
    // print(tail);
    // insertNode(tail, 9, 12);
    // print(tail);
    // insertNode(tail, 12, 56);
    // print(tail);
    // insertNode(tail, 56, 99);
    // print(tail);

    deleteNode(tail, 5);
    print(tail);
}
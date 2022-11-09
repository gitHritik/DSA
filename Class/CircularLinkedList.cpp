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
        while (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for " << value << endl;
    }
};

void insertNode(Node *&tail, string element, string name)
{

    if (tail == NULL)
    {
        Node *newNode = new Node(name);
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->name != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(name);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, string value)
{
    if (tail == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->name != value)
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

void print(Node *tail)
{
    Node *curr = tail;
    if (tail == NULL)
    {
        cout << "List is empty";
    }
    do
    {
        cout << tail->name << "->";
        tail = tail->next;
    } while (tail != curr);
    cout << endl;
}
int32_t main()
{

    Node *tail = NULL;
    insertNode(tail, "sonam", "hritik");
    print(tail);
    // insertNode(tail, "hritik", "sonam");
    // print(tail);
    // insertNode(tail, "hritik", "neha");
    // print(tail);
    // insertNode(tail, "sonam", "rahul");
    // print(tail);

    deleteNode(tail, "hritik");
    print(tail);
}
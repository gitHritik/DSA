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

bool isCircular(Node *head)
{
    if (head == NULL || head->next == head)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}
int32_t main()
{

    Node *tail = NULL;
    insertNode(tail, "sonam", "hritik");

    insertNode(tail, "hritik", "sonam");

    insertNode(tail, "hritik", "neha");

    insertNode(tail, "sonam", "rahul");

    print(tail);

    if (isCircular(tail))
    {
        cout << "Circular" << endl;
    }
    else
    {
        cout << "Not circular" << endl;
    }
}
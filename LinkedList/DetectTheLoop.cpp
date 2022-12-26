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

void insertAtMiddle(Node *&tail, Node *&head, int data, int pos)
{

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    Node *newNode = new Node(data);
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

bool detectCycle(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydsALgo(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout << "Present At " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *begginningOfLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydsALgo(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removoveLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *startingLoop = begginningOfLoop(head);
    Node *temp = startingLoop;
    while (temp->next != startingLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int32_t main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 3);
    insertAttail(tail, 3);
    insertAttail(tail, 3);
    insertAttail(tail, 3);
    insertAtMiddle(tail, head, 4, 6);
    // print(head);

    tail->next = head->next;

    if (floydsALgo(head) != NULL)
    {
        cout << "Circular Linked List" << endl;
    }
    else
    {
        cout << "Not circular" << endl;
    }

    Node *ans = begginningOfLoop(head);
    // cout << ans->data << endl;
    removoveLoop(head);
    print(head);
    if (floydsALgo(head) != NULL)
    {
        cout << "Circular Linked List" << endl;
    }
    else
    {
        cout << "Not circular" << endl;
    }
}
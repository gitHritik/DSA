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

bool DetectCycle(Node *head)
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
            cout << "The starting node of cycle is " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floyedAlog(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            // cout << "The starting node of cycle is " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *startingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *startNode = floyedAlog(head);

    Node *slow = head;

    while (slow != startNode)
    {
        slow = slow->next;
        startNode = startNode->next;
    }
    return slow;
}

void removeCycle(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startNode = floyedAlog(head);
    startNode->next = NULL;
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

    tail->next = head->next;

    // print(head);
    removeCycle(head);
    print(head);

    // Node *value = startingNode(head);
    // cout << value->data << endl;

    // if (DetectCycle(head))
    // {
    //     cout << "Cycle is present " << endl;
    // }
    // else
    // {
    //     cout << "Cycle is not present " << endl;
    // }
    // if (floyedAlog(head) != NULL)
    // {
    //     cout << "Cycle is present " << endl;
    // }
    // else
    // {
    //     cout << "Cycle is not present " << endl;
    // }
    // cout << "Head" << head->data << endl;
}
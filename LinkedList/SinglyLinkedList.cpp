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
void deleteNode(Node *&head, Node *&tail, int postion)
{

    // handling first node
    if (postion == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = head;
        int cnt = 1;
        while (cnt < postion)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        tail = prev;
        curr->next = NULL;
        delete curr;
    }
}
bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
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
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 3);
    insertAttail(tail, 3);
    insertAttail(tail, 3);
    insertAttail(tail, 3);
    insertAtMiddle(tail, head, 4, 6);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    deleteNode(head, tail, 6);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
    if (isCircular(head))
    {
        cout << "Ciruclar in natue";
    }
    else
    {
        cout << "Not Ciruclar in natue";
    }
}
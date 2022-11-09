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

int getSize(Node *head)
{

    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

int getMiddle(Node *head, int ans)
{
    Node *temp = head;

    int count = 1;
    while (count < ans)
    {
        temp = temp->next;
        count++;
    }

    return temp->data;
}

int getMiddle1(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head->data;
    }

    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }
    return slow->data;
}

int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 12);
    insertAtTail(tail, 3);

    insertAtTail(tail, 7);

    insertAtTail(tail, 5);
    insertAtTail(tail, 10);
    print(head);

    int size = getSize(head);

    int ans = (size / 2) + 1;
    int middle = getMiddle(head, ans);
    int middle2 = getMiddle1(head);

    cout << middle2;
}
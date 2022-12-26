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
Node *reverse(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertAtValue(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
Node *merge(Node *&first, Node *second)
{
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int val1 = 0;

    int carry = 0;

    while (first != NULL || second != NULL || carry != 0)
    {
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        int sum = carry + val1 + val2;
        int digit = sum % 10;

        // create new linked list
        insertAtValue(ansHead, ansTail, digit);

        carry = digit / 10;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }

    return ansHead;
}
Node *addTwoLinkedList(Node *&first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    // step1: Reverse Linked List
    first = reverse(first);
    second = reverse(second);

    // step2: add two linked list
    Node *ans = merge(first, second);

    // step3: reverse the ans linked list
    ans = reverse(ans);

    return ans;
}
int32_t main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *first = node1;
    Node *tailFirst = node1;
    Node *second = node2;
    Node *tailSecond = node2;

    insertAttail(tailFirst, 0);
    insertAttail(tailFirst, 0);
    insertAttail(tailSecond, 0);

    print(first);
    print(second);
    Node *ans = addTwoLinkedList(first, second);
    print(ans);
}
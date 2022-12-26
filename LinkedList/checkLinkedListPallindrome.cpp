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

bool isCorrect(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        if (arr[s] == arr[e])
        {
            s++;
            e--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// bool isPallindrome(Node *head)
// {
//     vector<int> arr;

//     Node *temp = head;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     if (isCorrect(arr))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

Node *getMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
// appraoch 2
bool isPallindrome(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    // finding the middle
    Node *middle = getMiddle(head);

    // reverse the linked list from the middle
    Node *temp = middle->next;
    middle->next = reverse(temp);

    // compare the halves
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // reverse the linked list from the middle
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 2);
    // insertAttail(tail, 1);
    // insertAttail(tail, 1);

    print(head);

    if (isPallindrome(head))
    {
        cout << "Pallindrome";
    }
    else
    {
        cout << "Not pallindrome";
    }
}
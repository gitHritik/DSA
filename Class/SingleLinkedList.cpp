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

void insertAtMiddle(Node *&head, Node *&tail, int pos, int d)
{
    Node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
    tail = newNode;
}
void deleteNode(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // prev->next = NULL;
        if (curr->next == NULL)
        {
            prev->next = NULL;

            tail = prev;
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
// bool isCircular(Node *head)
// {
//     if (head == NULL)
//     {
//         return true;
//     }
//     Node *temp = head->next;

//     while (temp != NULL && temp != head)
//     {
//         temp = temp->next;
//     }

//     if (temp == head)
//     {
//         return true;
//     }

//     return false;
// }
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
            cout << "The loop started from" << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floyedCycleAlgo(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
        if (fast == slow)
        {
            cout << "Cycle started at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *begginingOfLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = floyedCycleAlgo(head);

    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *startLoop = begginingOfLoop(head);
    Node *temp = startLoop;
    if (temp->next != startLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}
int32_t main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    // insertAtHead(head, 2);
    // print(head);
    // insertAtHead(head, 3);
    // print(head);

    insertAtTail(tail, 2);
    // print(head);

    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    tail->next = head->next->next;
    // print(head);

    // if (detectCycle(head))
    // {
    //     cout << "Cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "Not present" << endl;
    // }

    if (floyedCycleAlgo(head) != NULL)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Not present" << endl;
    }

    Node *startNode = begginingOfLoop(head);

    cout << startNode->data << endl;

    removeLoop(head);
    if (floyedCycleAlgo(head) != NULL)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Not present" << endl;
    }
    print(head);

    // if (isCircular(head))
    // {
    //     cout << "Linked List is circular";
    // }
    // else
    // {
    //     cout << "Linked List is not ciruclar";
    // }
    // deleteNode(head, tail, 2);
    // print(head);
    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;
}
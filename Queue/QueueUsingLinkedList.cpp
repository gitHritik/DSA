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
};

class Queue
{
public:
    Node *qfront;
    Node *rear;

    Queue()
    {
        qfront = NULL;
        rear = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (rear == NULL)
        {
            qfront = temp;
            rear = temp;
        }

        rear->next = temp;
        rear = temp->next;
    }

    int pop()
    {
        // check is queue is empty
        if (qfront == NULL)
        {
            return -1;
        }

        int ans = qfront->data;
        qfront = qfront->next;

        if (qfront == rear)
        {
            qfront = rear = NULL;
        }
        return ans;
    }
};
int32_t main()
{

    Queue q;
    q.push(33);
    q.push(3);
    q.push(23);
    q.push(133);
    cout << (q.qfront)->data << endl;
    q.pop();
    cout << (q.qfront)->data << endl;
}
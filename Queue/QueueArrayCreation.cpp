#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class Queue
{

    int *arr;
    int qfront, rear;
    int size;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        rear = 0;
        qfront = 0;
    }

    void push(int data)
    {
        // check is queue is full
        if (rear == size)
        {
            cout << "Queue is full";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int pop()
    {
        // check is queue is empty
        if (qfront == rear)
        {
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            rear = 0;
            qfront = 0;
        }

        return ans;
    }

    int front()
    {
        // check is queue empty
        if (qfront == rear)
        {
            return -1;
        }

        return arr[qfront];
    }

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int32_t main()
{
    Queue q;
    q.push(44);
    q.push(4);
    q.push(14);
    q.push(94);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}
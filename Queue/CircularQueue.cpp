#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class CircularQueue
{
public:
    int *arr;
    int qfront, rear;
    int size;

    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        // first check queue is full
        if ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            cout << "Queue is full";
            return false;
        }
        else if (qfront == -1)
        {
            qfront = rear = 0;
        }
        else if (rear == size - 1 && qfront != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // check wheather queue is empty
        if (qfront == -1)
        {
            cout << "Queue is empty";
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        if (qfront == rear)
        {
            qfront = -1;
            rear = -1;
        }
        else if (qfront == size - 1)
        {
            qfront = 0;
        }
        else
        {
            qfront++;
        }
        return ans;
    }
};
int32_t main()
{
    CircularQueue q;
    q.enqueue(3);
    q.enqueue(23);
    q.enqueue(13);
    cout << q.qfront() << endl;
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // cout << q.qfront() << endl;
    cout << q.qfront() << endl;
}
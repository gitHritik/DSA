#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

#include <bits/stdc++.h>
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

    /*----------------- Public Functions of Queue -----------------*/

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

    void enqueue(int data)
    {

        // check if the queueu is full
        if (rear == size - 1)
        {
            cout << "Queue is full";
            return;
        }

        arr[rear] = data;
        rear++;
    }

    int dequeue()
    {
        // check queue if empty
        if (rear == qfront)
        {
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }

        return ans;
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        return arr[qfront];
    }
};
int32_t main()
{
    Queue q;
    q.enqueue(3);
    q.enqueue(23);
    q.enqueue(13);
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // cout << q.front() << endl;
    cout << q.front() << endl;
}
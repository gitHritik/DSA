#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class kQueues
{
public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
    int n, k;

    kQueues(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freespot = 0;
    }

    void enqueue(int x, int qn)
    {
        // check if the queue is full
        if (freespot == -1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        // find the free spot first
        int index = freespot;

        // update the free sport
        freespot = next[index];

        // check if we are pushing first elemet in queue
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index; // here we are linking the previous queue with next one
        }

        // update the next where we are pushing the element
        next[index] = -1;

        // update the rear where we are pushing the element
        rear[qn - 1] = index;

        // push the element in array
        arr[index] = x;
    }

    int dequeue(int qn)
    {
        // check wheather the queue is empty
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // find the index which we have to delete
        int index = front[qn - 1];

        // increase the front
        front[qn - 1] = next[index];

        // now link the free sport
        next[index] = freespot;

        // now the element we have deleted we need to  make it freesport
        freespot = index;

        return arr[index];
    }
};
int32_t main()
{
    kQueues q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack is overflow" << endl;
        }
    }

    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            cout << "stack is underflow" << endl;
        }
    }

    int peek()
    {
        if (top != -1)
        {
            return arr[top];
        }
        else
        {
            cout << "No element is present at top" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
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

    Stack s(5);
    s.push(4);
    s.push(2);
    s.push(12);

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    if (s.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack not is empty" << endl;
    }
}
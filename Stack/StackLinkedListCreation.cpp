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

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        temp->data = data;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "Stack underflow" << endl;
        }
        temp = top;
        top = top->next;
        free(temp);
    }

    int display()
    {
        if (top == NULL)
        {
            cout << "No element is present" << endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty()
    {
        if (top == NULL)
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
    Stack s;
    s.push(4);
    s.push(14);
    s.push(84);

    cout << s.display() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << s.display() << endl;

    if (s.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack not is empty" << endl;
    }
}
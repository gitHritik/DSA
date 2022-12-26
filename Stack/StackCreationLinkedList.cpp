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

        if (!temp)
        {
            cout << "Stack overflow" << endl;
            return;
        }

        temp->data = data;

        temp->next = top;

        top = temp;
    }

    void pop()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        temp = top;

        top = top->next;

        free(temp);
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

    int peek()
    {
        if (top != NULL)
        {
            return top->data;
        }
        else
        {

            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    void display()
    {
        if (top == NULL)
        {
            cout << "Not exist" << endl;
            return;
        }

        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int32_t main()
{

    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    st.display();
    cout << "Top element is" << st.peek() << endl;

    st.pop();
    st.display();

    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {

        cout << "Stack is not empty" << endl;
    }
}
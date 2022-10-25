#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class hritik
{
private:
    int password;

public:
    string name;
    static int no;

    hritik()
    {
        cout << "Constuctor Called" << endl;
    }

    // Paramaterized Constructor
    hritik(int password, string name)
    {
        this->password = password;
        this->name = name;
    }

    // copy constructor
    hritik(hritik &temp)
    {

        cout << "Copy constructor" << endl;
        this->password = temp.password;
        this->name = temp.name;
    }

    void print()
    {
        cout << password << endl;
        cout << name << endl;
    }
    int getMethod()
    {
        return password;
    }
    void setMethod(int p)
    {
        password = p;
    }
    static int random()
    {
        return no;
    }
};
int hritik::no = 2;

int main()
{
    // static keyword here it will not matter form object beacue it doesn't belong to it;
    // static value
    cout << hritik::no << endl;
    // static funtion
    cout << hritik::random() << endl;

    // copy assingemt opertor
    // hritik h(110023, "Hritik");
    // hritik p(h);
    // p.print();
    // h.name = "neha";
    // h.print();
    // p.print();
    // h = p;
    // h.print();

    // hritik h(110023, "Hritik");
    // h.print();
    // hritik p(h);
    // p.print();
    // h.name = "neha";
    // h.print();

    // p.print();

    // copy constructor
    // hritik p(h);
    // p.print();

    // Paramerterised constructor
    //  hritik h(110023, "Hritik");
    //  h.print();

    // cout << "Hi" << endl;
    // hritik h;
    // cout << "Hello" << endl;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class hritik
{
private:
    string name;
    int age;

    int getAge()
    {
        return this->age;
    }
};
class Sname : private hritik
{
public:
    string color;
    void getName(string name)
    {
        this->name = name;
    }

    string n()
    {
        return this->name;
    }
};
int32_t main()
{

    // inherit
    Sname n;
    n.getName("hritik");
    cout << n.n() << endl;

    // hritik h1;
    // h1.getAge();
    // h1.
}

// superclass    subclass     result
// public        public       public  accessible in child class and even outside the class
// public        private      private  accessible in childe class but not in outside child class
// public        protected    protected accessible in childe class but not in outside child class

// protected     public       protected  accessible in childe class but not in outside child class
// protected     protected    protected  accessible in childe class but not in outside child class
// protected     private      private     accessible in childe class but not in outside child class

// private       public        Not accessible Not accessible in child class and not even outside the class
// private       protected     Not accessible Not accessible in child class and not even outside the class
// private       private       Not accessible Not accessible in child class and not even outside the class

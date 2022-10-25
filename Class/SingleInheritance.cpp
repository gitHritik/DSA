#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class Animal
{
public:
    void speak()
    {
        cout << "Speak" << endl;
    }
};

class Dog : public Animal
{

public:
    void bark()
    {
        cout << "Bow wow" << endl;
    }
};
int32_t main()
{
    Dog d;
    d.speak();
    d.bark();
}
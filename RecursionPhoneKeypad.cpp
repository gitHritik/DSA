#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void solve(string digits, string output, int index, string mapping[])
{
    // base case
    if (index >= digits.length()) // when index will cross digist like in 26 i corss 6
    {
        cout << output << " "; // When i corss both the nos then ihen out put will be store
        return;
    }

    int number = digits[index] - '0'; // here we are finding that no liek in di
    // numer = '2' - '0' = 2;

    string value = mapping[number]; // value will be 2nd index on mapping like abc

    for (int i = 0; i < value.length(); i++) // traversing through abc
    {
        output.push_back(value[i]);                // pushing a b c
        solve(digits, output, index + 1, mapping); // next no like when i increase then am an ao
        output.pop_back();                         // then we take back a so we can travere into b
    }
}
int32_t main()
{
    string digits = "";       // value of keypad
    string output = "";       // here we will store output
    if (digits.length() == 0) // digits is empty then output as empty
    {
        cout << output;
    }

    int index = 0;
    string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // Mark down index accding to nos on keypad

    solve(digits, output, index, mapping);
}

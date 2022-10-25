#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void solve(string digits, int index)
{
    if (index >= digits.length()) //if i becomes greater then lenght of string then it has reched the last position
    {
        cout << digits << " ";//so everthing stored in digits
        return;
    }

    for (int j = index; j < digits.length(); j++) //looping from first to last element in string
    {
        swap(digits[index], digits[j]);//swap first index with b and then c
        solve(digits, index + 1);//recursion solve next iterration till i>length

        //backtracking because when we go back after solving a iteration now we watn string as same "abc" beacue 
        //when we do "bac" we want back "abc"
        
    }
}
int32_t main()
{
    string digits = "abc";
    int index = 0;
    solve(digits, index);
}
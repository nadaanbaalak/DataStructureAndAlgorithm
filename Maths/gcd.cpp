/*
Given two numbers a & b, find the gcd of the two numbers.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (a % b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    cout << b << endl;
    return 0;
}

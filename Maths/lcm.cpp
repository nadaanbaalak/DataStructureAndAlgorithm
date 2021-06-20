/*
finding the lcm of two numbers a & b
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int i = 2, temp = a;
    while (temp % b != 0)
    {
        temp = a * i;
        i++;
    }
    cout << temp << endl;
    return 0;
}
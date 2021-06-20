/*
Given a number N, check if it's prime or not
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Prime";
    else
        cout << "Not Prime";
    return 0;
}
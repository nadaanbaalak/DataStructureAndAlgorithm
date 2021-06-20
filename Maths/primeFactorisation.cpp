/*
Given a number 'N', find it's prime factors. 
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num = n;
    for (int i = 2; i * i <= num; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            cout << i << " ";
        }
    }
    if (n != 1)
        cout << n << endl;
    return 0;
}

// Time Complexity : O(N^(1/2))
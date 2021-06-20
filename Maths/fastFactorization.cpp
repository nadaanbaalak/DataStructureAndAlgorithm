/*
We know that time complexity of finding prime factors of a number is O(N^(1/2)) 
but this is for one number what if we want for say 'Q' numbers, Time complexity would be Q*(N^(1/2)) 
*/
#include <bits/stdc++.h>
using namespace std;
#define M 100000

void prime(vector<bool> &v, vector<int> &spf)
{
    v[0] = false;
    v[1] = false;
    for (int i = 2; i * i <= (M + 1); i++)
    {
        if (!v[i])
            continue;
        for (int j = i * i; j <= (M + 1); j = j + i)
        {
            if (v[j])
            {
                spf[j] = i;
                v[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<bool> primes(M + 1, true);
    vector<int> spf(M + 1, -1);
    prime(primes, spf);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (spf[x] != -1)
        {
            cout << spf[x] << " ";
            x = x / spf[x];
        }
        if (x != 0)
            cout << x;
    }
    return 0;
}
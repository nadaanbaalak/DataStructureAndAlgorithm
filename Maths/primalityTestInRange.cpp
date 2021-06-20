/*
Given a range of numbers from 1 to N, find all the prime numbers in the range.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<bool> range(n + 1, true);
    for (int i = 2; i * i < n; i++)
    {
        if (!range[i])
            continue;
        // SLIGHT IMPROVEMENT CAN BE : instead of starting from i*2, we can start from i*i as i*2, i*3..i*(i-1) would be cut out by 2*i,3*i and so on..
        for (int j = i * i; j < n + 1; j = j + i)
        {
            range[j] = false;
        }
    }
    for (int i = 2; i < n + 1; i++)
    {
        if (range[i])
            cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity : 
This runs for N/2 + N/3 + N/5 + N/7... ===> N(1/2 + 1/3 + 1/5 + 1/7 +..) ==> N(log(log N));
*/
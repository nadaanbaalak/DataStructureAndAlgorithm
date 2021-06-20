/*
Find the sum of all sub arrays of an array
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //brute force approach T(n) = O(n^2)
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        int subarraySum = 0;
        for (int j = i; j < n; j++)
        {
            subarraySum += arr[j];
            totalSum += subarraySum;
        }
    }
    //Reverse Lookup: We calculate the contribution of each element
    //an element a[i] will be part of all subarray having starting index from 0 to (i+1) and ending index from (i+1) to (n-1)
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = ((sum) % m + (((i + 1) % m) * ((n - i) % m) * (arr[i] % m)) % m) % m;
    }
    cout << totalSum << " " << sum;
    return 0;
}
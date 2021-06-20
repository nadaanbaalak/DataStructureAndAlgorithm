/*
Given an array arr[N], rearrange such that if a[i] = k, a[k]=i
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int oldValue;
    for (int i = 0; i < n; i++)
    {
        oldValue = arr[i] % n;
        arr[oldValue] = n * i + arr[oldValue];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / n;
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
In this we try to store both values such that we can extract whenever we need any of the values i.e old and new.
*/
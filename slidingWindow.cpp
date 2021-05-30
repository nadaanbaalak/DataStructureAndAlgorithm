#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int subarraySum = 0;
    //printing sum of subarray of size k
    for (int i = 0; i < k; i++)
    {
        subarraySum += arr[i];
    }
    for (int i = k; i <= (n - k); i++)
    {
        cout << subarraySum << endl;
        subarraySum += (arr[i] - arr[i - k + 1]);
    }
    cout << subarraySum;
    return 0;
}
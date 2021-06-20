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
    //calculating the sum of very first subarray of size k
    for (int i = 0; i < k; i++)
    {
        subarraySum += arr[i];
    }
    //moving the window ahead by 1 step by starting from k as already calculated the sum for 1st window.
    for (int i = k; i <= (n - k); i++)
    {
        cout << subarraySum << endl;              //printing sum of subarray of size k
        subarraySum += (arr[i] - arr[i - k + 1]); //removing last element of previous window and adding the start of next window
    }
    cout << subarraySum;
    return 0;
}
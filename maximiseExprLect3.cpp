#include <bits/stdc++.h>
using namespace std;

void prefixMax(vector<int> &pm, int arr[], int size)
{
    pm.push_back(arr[0]);
    int maxTillNow = arr[0];
    for (int i = 1; i < size; i++)
    {
        maxTillNow = (arr[i] > maxTillNow) ? arr[i] : maxTillNow;
        pm.push_back(maxTillNow);
    }
    return;
}

void suffixMax(vector<int> &sm, int arr[], int size)
{
    sm[size - 1] = arr[size - 1];
    int maxTillNow = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        maxTillNow = (arr[i] > maxTillNow) ? arr[i] : maxTillNow;
        sm[i] = maxTillNow;
    }
    return;
}

int main()
{
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> pm, sm(n);
    prefixMax(pm, arr, n);
    suffixMax(sm, arr, n);
    int i, k;
    int pMax = INT_MIN, maxVal = INT_MIN, rMax = INT_MIN;
    for (int j = 1; j < n - 1; j++)
    {
        pMax = max(pMax, p * pm[j - 1]);
        rMax = max(rMax, r * sm[j + 1]);
        maxVal = max(maxVal, (pMax + rMax + q * arr[j]));
    }
    cout << maxVal << endl;
    return 0;
}

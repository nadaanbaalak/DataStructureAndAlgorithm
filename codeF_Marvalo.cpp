#include <bits/stdc++.h>
using namespace std;
#define ll long long
void prefixMax(ll pm[], ll arr[], ll size, ll p)
{
    ll max = p * arr[0];
    pm[0] = p * arr[0];
    for (ll i = 1; i < size; i++)
    {
        if (max < (p * arr[i]))
        {
            max = p * arr[i];
        }
        pm[i] = max;
    }
    return;
}

void suffixMax(ll sm[], ll arr[], ll size, ll r)
{
    ll max = r * arr[size - 1];
    sm[size - 1] = r * arr[size - 1];
    for (ll i = size - 2; i >= 0; i--)
    {
        if (max < (r * arr[i]))
        {
            max = r * arr[i];
        }
        sm[i] = max;
    }
    return;
}

// void printArr(long long arr[], long long size)
// {
//     for (long long i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

int main()
{
    ll n;
    ll p, q, r;
    cin >> n >> p >> q >> r;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll sm[n], pm[n];
    prefixMax(pm, arr, n, p);
    suffixMax(sm, arr, n, r);
    // ll pMax = LLONG_MIN;
    // ll rMax = LLONG_MIN;
    ll qMax = LLONG_MIN;
    ll maxVal = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {

        qMax = q * arr[i];
        maxVal = max(maxVal, (pm[i] + qMax + sm[i]));
    }
    cout << maxVal << endl;
    return 0;
}

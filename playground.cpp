#include <bits/stdc++.h>
using namespace std;
void suffixMax(vector<int> &sm, vector<int> &prices)
{
    int size = prices.size();
    int maxSoFar = prices[size - 1];
    sm[size - 1] = maxSoFar;
    for (int i = size - 2; i >= 0; i--)
    {
        if (prices[i] > maxSoFar)
        {
            maxSoFar = prices[i];
        }
        sm[i] = maxSoFar;
    }
    return;
}
int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    cout << size;
    vector<int> sm(size);
    suffixMax(sm, prices);
    int ans = INT_MIN;
    for (int i = 0; i < size - 1; i++)
    {
        if (sm[i + 1] - prices[i] > ans)
            ans = sm[i + 1] - prices[i];
    }
    return (ans > 0 ? ans : 0);
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices);
    return 0;
}
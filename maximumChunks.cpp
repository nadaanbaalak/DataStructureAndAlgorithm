#include <bits/stdc++.h>
using namespace std;

bool canBeChunked(int i, int j, int arr[])
{
    for (int k = i; k <= j; k++)
    {
        if (arr[k] <= j && arr[k] >= i)
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n;)
    {
        int j;
        for (j = i; j < n; j++)
        {
            if (canBeChunked(i, j, arr))
                break;
        }
        i = j + 1;
        ans++;
    }
    cout << ans;
    return 0;
}
/*
Generate all factors of N...remember that factors are symmetric about N^(1/2)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                cout << i;
            else
            {
                cout << i << " " << (n / i) << " ";
            }
        }
    }
    cout << endl;
    int x = sqrt(n);
    if (x * x == n)
        cout << "odd" << endl;
    else
        cout << "Even" << endl;
    return 0;
}
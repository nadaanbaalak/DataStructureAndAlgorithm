#include <bits/stdc++.h>
using namespace std;
#define M 3
#define N 3

int main()
{
    int arr[M][N];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    int topLeft = 0, bottomRight = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            topLeft = (i + 1) * (j + 1);
            bottomRight = (N - i) * (M - j);
            sum += topLeft * bottomRight * arr[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}

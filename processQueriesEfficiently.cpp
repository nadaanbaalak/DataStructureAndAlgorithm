/*
Given a 2-D array and queries of form (i,j,k,l) where (i,j) are top-left coordinates 
and (k,l) are bottom-right co-ordinate of array, find sum of element of such matrices. There could be Q such queries
*/
#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 5

void prefixSum2D(int arr[M][N])
{
    //rowwise sum
    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum += arr[i][j];
            arr[i][j] = sum;
        }
    }
    //column wise
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
        {
            sum += arr[j][i];
            arr[j][i] = sum;
        }
    }
    return;
}

int sumOfMatrix(int i, int j, int k, int l, int arr[M][N])
{
    int part1, part2, part3;
    if ((j - 1) >= 0)
        part1 = arr[k][j - 1];
    if ((i - 1) >= 0)
        part2 = arr[i - 1][l];
    if ((i - 1) >= 0 && (j - 1) >= 0)
        part3 = arr[i - 1][j - 1];
    int sumOfMatrix = arr[k][l] - part1 - part2 + part3;
    return sumOfMatrix;
}

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
    //modifying same array
    prefixSum2D(arr);
    int i, j, k, l;
    cin >> i >> j >> k >> l;
    cout << sumOfMatrix(i, j, k, l, arr);
    return 0;
}
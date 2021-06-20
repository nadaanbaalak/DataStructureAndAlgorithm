/*
Given an array and a number 'k', find the min number of swaps required to bring all elements smaller than 'k' together
ex: 
Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
Output :  2 
Link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int windowSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            windowSize++;
    }
    cout << "Window Size = " << windowSize << endl;
    int minSwapsInAnySubarray = INT_MAX;
    int swapsSoFar = windowSize;
    for (int i = 0; i < windowSize; i++)
    {
        if (arr[i] <= k)
            swapsSoFar--;
    }
    cout << "Swaps So Far " << swapsSoFar << endl;
    minSwapsInAnySubarray = swapsSoFar;
    for (int i = windowSize; i < n; i++)
    {
        if (arr[i] > k && arr[i - windowSize] <= k)
            swapsSoFar++;
        else if (arr[i] <= k && arr[i - windowSize] > k)
            swapsSoFar--;

        if (minSwapsInAnySubarray > swapsSoFar)
            minSwapsInAnySubarray = swapsSoFar;
        cout << "minSwaps, swapsSoFar " << minSwapsInAnySubarray << " " << swapsSoFar << endl;
    }
    cout << minSwapsInAnySubarray << endl;
    return 0;
}
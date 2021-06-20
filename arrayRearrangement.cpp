/*
Given an array of size 'N', having elements from 0 to 'N-1'(in any order),
rearrange the array such that if arr[i] = k, arr[k] = i
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //simple but with O(N) space complexity
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]] = i;
    }
    /*Another method without extra space, checking if the element has been part of cycle,
    if yes...move on and if no, start the cycle*/
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            int index = arr[i];
            int val = i;
            while (index != i)
            {
                int temp = arr[index];
                arr[index] = -(val + 1);
                val = index;
                index = temp;
            }
            arr[index] = -(val + 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1 * arr[i] - 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
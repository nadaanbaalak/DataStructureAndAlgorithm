/*
Given an array of size 'N', find max consecutive difference between 2 elements. 
Note: Consecutive difference means the difference between 2 consecutive elements in sorted array. 
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
    int max = INT_MIN, min = INT_MAX;
    //finding max and min of the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    //min possible value of max consecutive difference, it divided by 'n-1' cause thats the number of gaps in b/w.
    int gap = (max - min) % (n - 1) == 0 ? ((max - min) / (n - 1)) : (((max - min) / (n - 1)) + 1);
    //Possible case of all elements being equal, the gap would be 0, so if we need to return 0;
    if (gap == 0)
        return 0;
    //vectors to store min and max of each bucket denoted by "i"
    vector<int> maxInBucket(n, INT_MIN);
    vector<int> minInBucket(n, INT_MAX);
    int bucketNumber;
    //filling arrays with min and max values of bucket
    for (int i = 0; i < n; i++)
    {
        bucketNumber = (arr[i] - min) / gap;
        if (maxInBucket[bucketNumber] < arr[i])
            maxInBucket[bucketNumber] = arr[i];
        if (minInBucket[bucketNumber] > arr[i])
            minInBucket[bucketNumber] = arr[i];
    }
    int maxConsecutiveDifference = INT_MIN;
    int prevMax = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        if (maxInBucket[i] == INT_MIN)
            continue;
        if (prevMax == INT_MIN)
            prevMax = maxInBucket[i];
        else
        {
            maxConsecutiveDifference = std::max(minInBucket[i] - prevMax, maxConsecutiveDifference);
            prevMax = maxInBucket[i];
        }
    }
    cout << maxConsecutiveDifference << endl;
    return 0;
}

/*
Brute force would have been sorting the array and then storing max difference. T(N) = O(n*log(n))
*/
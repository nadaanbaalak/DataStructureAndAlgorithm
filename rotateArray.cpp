#include <bits/stdc++.h>
using namespace std;
void rotateByOne(int arr[], int size)
{
    int lastElement = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = lastElement;
    return;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reversal(vector<int> &nums, int i, int j)
{
    int temp;
    while (i < j)
    {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
    return;
}
void rotate(vector<int> &nums, int k)
{
    int pivot = nums.size() - k;
    int i = 0, j = pivot - 1;
    reversal(nums, i, j);
    i = pivot;
    j = nums.size() - 1;
    reversal(nums, i, j);
    i = 0;
    j = nums.size() - 1;
    reversal(nums, i, j);
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    //Brute-force way to rotate. Time-complexity: O(K*N), where N=size of array, K=units by which array is rotated
    for (int i = 1; i < (k%n); i++)
    {
        rotateByOne(arr, n);
    }
    printArr(arr, n);

    //Optimised solution in O(N) but with extra space complexity
    int temp[n];
    for(int i=0;i<n;i++)
    {
        temp[(i+k)%n] = arr[i];
    }
    printArr(temp, n);
    return 0;
}
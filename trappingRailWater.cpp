#include <bits/stdc++.h>
using namespace std;
void prefixMax(vector<int> &pm, int arr[], int size)
{
    pm.push_back(arr[0]);
    int maxVal = pm[0];
    for (int i = 1; i < size; i++)
    {
        maxVal = (maxVal < arr[i]) ? arr[i] : maxVal;
        pm.push_back(maxVal);
    }
    return;
}

void suffixMax(vector<int> &sm, int arr[], int size)
{
    sm[size - 1] = arr[size - 1];
    int maxVal = sm[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        maxVal = (maxVal < arr[i]) ? arr[i] : maxVal;
        sm[i] = maxVal;
    }
    return;
}

int main()
{
    int maxHeightPillarOnLeft, maxHeightPillarOnRight, numberOfPillars;
    cin >> numberOfPillars;
    int pillarHeights[numberOfPillars];
    for (int i = 0; i < numberOfPillars; i++)
    {
        cin >> pillarHeights[i];
    }
    vector<int> pm, sm(numberOfPillars);
    suffixMax(sm, pillarHeights, numberOfPillars);
    prefixMax(pm, pillarHeights, numberOfPillars);
    int totalWaterTrapped = 0;
    int waterHeightOnPillar;
    for (int i = 1; i < (numberOfPillars - 1); i++)
    {
        maxHeightPillarOnLeft = pm[i - 1];
        maxHeightPillarOnRight = sm[i + 1];
        waterHeightOnPillar = (maxHeightPillarOnLeft > pillarHeights[i] && maxHeightPillarOnRight > pillarHeights[i]) ? (min(maxHeightPillarOnLeft, maxHeightPillarOnRight) - pillarHeights[i]) : 0;
        cout << "Water Trapped on this pillar " << i << " is " << waterHeightOnPillar << endl;
        totalWaterTrapped += waterHeightOnPillar;
    }
    cout << "Water Trapped : " << totalWaterTrapped << endl;
    return 0;
}
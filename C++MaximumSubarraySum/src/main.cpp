#include <bits/stdc++.h>
using namespace std;

int maxSubArray1(int array[], int n);
int maxSubArray2(int array[], int n);
int maxSubArray3(int array[], int n); // Kadane's algorithm
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << maxSubArray1(array, n) << "\n";
    cout << maxSubArray2(array, n) << "\n";
    cout << maxSubArray3(array, n) << "\n";
    return 0;
}

int maxSubArray1(int array[], int n)
{
    int sum = 0;
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                sum += array[k];
            }
            best = max(sum, best);
            sum = 0;
        }
    }
    return best;
}

int maxSubArray2(int array[], int n)
{
    int sum = 0;
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += array[j];
            best = max(sum, best);
        }
        sum = 0;
    }
    return best;
}

int maxSubArray3(int array[], int n) // Kadane's Algorithm
{
    int sum = 0;
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(array[i], sum + array[i]);
        best = max(best, sum);
    }
    return best;
}

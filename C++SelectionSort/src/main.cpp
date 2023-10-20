#include <bits/stdc++.h>

using namespace std;

void selectionSort(int array[], int n);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len = 0;

    cin >> len;

    int array[len];
    for (int i = 0; i < len; i++)
    {
        cin >> array[i];
    }

    selectionSort(array, len);

    for (int i : array)
    {
        cout << i << " ";
    }

    cout << "\n";
    return 0;
}

void selectionSort(int array[], int n)
{
    int minValue = 0;
    int position = 0;
    for (int j = 0; j < n; j++)
    {
        minValue = array[j];
        for (int i = j; i < n; i++)
        {
            if (minValue >= array[i])
            {
                minValue = array[i];
                position = i;
            }
        }
        array[position] = array[j];
        array[j] = minValue;
    }
}
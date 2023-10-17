#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int array[], int n);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int length = 0;
    cin >> length;

    int array[length];

    for (int i = 0; i < length; i++)
    {
        cin >> array[i];
    }

    bubbleSort(array, length);

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n";
    return 0;
}

void bubbleSort(int array[], int n)
{
    int temporal = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temporal = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporal;
            }
        }
    }
}
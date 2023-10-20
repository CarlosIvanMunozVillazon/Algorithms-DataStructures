#include <bits/stdc++.h>

using namespace std;

void insertionSort(int array[], int n);
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

    insertionSort(array, len);

    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n";
    return 0;
}

void insertionSort(int array[], int n)
{
    int temporal = 0;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        temporal = array[i];
        j = i - 1;
        while (array[j] > temporal && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        j++;
        array[j] = temporal;
    }
}
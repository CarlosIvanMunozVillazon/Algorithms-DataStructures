#include <iostream>

using namespace std;

int *mergeSort(int array[], int n);
void bubbleSort(int array[], int n);
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    int myArray[n];

    for (int i = 0; i < n; i++)
    {
        cin >> myArray[i];
    }

    int *sortedArray = new int[n];

    sortedArray = mergeSort(myArray, n);

    for (int i = 0; i < n; i++)
    {
        cout << sortedArray[i] << " ";
    }

    cout << "\n";

    delete[] sortedArray;
    sortedArray = NULL;
    return 0;
}

int *mergeSort(int array[], int n)
{
    // Halve the array.
    int k = n / 2;
    int j = n - k;
    int *left = new int[k];
    int *right = new int[j];

    int *arrayReturn = new int[n];

    for (int i = 0; i < k; i++)
    {
        left[i] = array[i];
    }

    for (int i = k; i < n; i++)
    {
        right[i - k] = array[i];
    }

    // See if we can sort faster
    if (n <= 4)
    {
        // sort left & right by bubble sort
        bubbleSort(left, k);
        bubbleSort(right, j);
    }
    else
    {
        // sort left & right by merge sort
        left = mergeSort(left, k);
        right = mergeSort(right, j);
    }

    // Merge the sorted sub arrays.
    int leftIndex = 0;
    int rightIndex = 0;
    int arrayReturnIndex = 0;
    while (leftIndex < k && rightIndex < j)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arrayReturn[arrayReturnIndex] = left[leftIndex];
            leftIndex++;
        }
        else
        {
            arrayReturn[arrayReturnIndex] = right[rightIndex];
            rightIndex++;
        }
        arrayReturnIndex++;
    }

    while (leftIndex < k)
    {
        arrayReturn[arrayReturnIndex] = left[leftIndex];
        leftIndex++;
        arrayReturnIndex++;
    }

    while (rightIndex < j)
    {
        arrayReturn[arrayReturnIndex] = right[rightIndex];
        rightIndex++;
        arrayReturnIndex++;
    }

    delete[] left;
    delete[] right;
    left = NULL;
    right = NULL;

    return arrayReturn;
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
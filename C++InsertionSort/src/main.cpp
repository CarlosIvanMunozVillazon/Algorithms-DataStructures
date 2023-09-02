#include <iostream>
using namespace std;

void printArray(int A[], int n);
void insertionSort(int A[], int n);

int main()
{

    int array_1[] = {5, 4, 3, 2, 1, 0};
    int arraySize = (int)(sizeof(array_1) / sizeof(int));

    printArray(array_1, arraySize);
    insertionSort(array_1, arraySize); //The function modifies the array located in memory :0
    printArray(array_1, arraySize);

    return 0;
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << ", ";
    };

    cout << " " << endl;
}

void insertionSort(int A[], int n)
{
    // n: array length, i: second element of the array
    int i = 1;

    while (i < n)
    {
        
        int key = A[i];
        int j = i - 1;

        while ((j >= 0) && (A[j] > key))
        {

            A[j+1] = A[j];
            j--;

        }

        A[j + 1] = key;
        i++;
    }

    // Don't know how to return a pointer, thats why i print it.
    printArray(A, n);
}
#include <iostream>
using namespace std;

int findMinimum(int array[], int position, int arraySize);
void arrayPrinter(int *arrayPointer, int range);
void selectionSort(int array[], int arraySize);

int main()
{

    cout << "Selection Sort" << endl;
    cout << "By: Carlos Ivan Muñoz Villazon" << endl;

    int testArray[5] = {5, 4, 3, 2, 1};
    int arraySize = sizeof(testArray) / sizeof(testArray[0]);

    selectionSort(testArray, arraySize);

    int *testArrayPointer;
    testArrayPointer = &testArray[0];
    arrayPrinter(testArrayPointer, arraySize);

    return 0;
}

// Function that returns the position of the minimum element from the beginning of the array till the end of the array.
int findMinimum(int array[], int position, int arraySize)
{

    int p = position;
    int number = array[position];

    for (int i = position + 1; i < arraySize; i++)
    {
        if (array[i] <= number)
        {
            number = array[i];
            p = i;
        }
    }

    return p;
}

// Function that constructs a sorted array by finding the minimum elements of the subarray and putting them in the correct
// positions.
void selectionSort(int array[], int arraySize)
{
    int i = 0;
    while (i < arraySize)
    {
        int minimumFoundPosition = findMinimum(array,i,arraySize);

        int key = array[i];
        array[i] = array[minimumFoundPosition];
        array[minimumFoundPosition] = key;

        i++;
    }
}

void arrayPrinter(int *arrayPointer, int range)
{
    for (int i = 0; i < range; i++)
    {
        cout << (*arrayPointer) << " ";
        arrayPointer++;
    }

    cout << "" << endl;
}
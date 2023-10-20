#include <iostream>
using namespace std;

int findMin(int array[], int length); // i love this syntax for parsing arrays to functions. We parse to the function the address of
// the array.
int findMax(int array[], int length);
void getMaxAndMin(int array[], int length, int *max, int *min); // when a function has as parameter a pointer, means we have
// to pass it either a pointer or a address. This means the function is going to change the directly the values that are stored
// in this addresses.

char *findChar(char name[], char letterToSearch);

char *fooFunction();
void gooFuntion();

char *fooFunction2();

int *invertArray(int array[], int size);

int main()
{
    // In this task we are going to learn how to return multiple values from a function using pointers.

    // First we are going to create two functions which return the max and the min of an array, and then we will create a function
    // that returns both of this values.

    // 1. Test function findMin:
    int testArray[5] = {2, 17, -32, 56, 12};
    cout << findMin(testArray, sizeof(testArray) / sizeof(testArray[0])) << endl;
    cout << testArray << endl;

    // 2. Test function findMax:
    int testArray2[5] = {15, 42, 189, 3232, 1};
    cout << findMax(testArray2, sizeof(testArray2) / sizeof(testArray2[0])) << endl;

    // 3. Test function getMaxAndMin:
    // If we do not pass an address to a function which receives pointers, then it will create a copy of the variable and make
    // the changes, but we are not going to be able to see them.

    int max = testArray2[0]; // When allocating this variables we are not altering the adresses of the array.
    int min = testArray2[0];

    getMaxAndMin(testArray2, sizeof(testArray2) / sizeof(testArray2[0]), &max, &min);

    // cout << max << endl;
    // cout << min << endl;

    // 4. How to return a pointer from a function safely? Let's say we want to print a string from a character we found.
    char name[] = "Carlos"; // We can declare a string as a char array.

    char *letter = findChar(name, 's');
    cout << *letter << endl;
    cout << name << endl;    // Prints the whole array as if it was a string.
    cout << &letter << endl; // Prints the address of the pointer
    cout << letter << endl;  // Bce it holds a char it doesn't prints the address hold by the pointer, instead prints directly the char

    // 5. Scope of variables.
    char *charPtr = fooFunction();
    cout << *charPtr << endl; // We get the data that comes from the memory allocation.
    gooFuntion();
    cout << *charPtr << endl; // but once another function is executed we lost that information.

    // good practice
    char *charPtr2 = fooFunction2();
    cout << *charPtr2 << endl;
    gooFuntion();
    cout << *charPtr2 << endl; // Data is preserved.

    // it is always good to delete the information held by pointers for avoiding memory leaks
    // delete charPtr; // yields and error cause it is an invalid pointer
    delete charPtr2;
    charPtr2 = NULL;

    // the "new" keyword requests memory space to allocate the neccessary space for the requested datatype
    // if there is enough memory the address of that memory is returned to be held by a pointer. Then we
    // can use the pointer to allocate that memory with information.

    // 6. Test with array: I want to make a function that returns a new array but inverted.

    int myArray[5] = {1, 2, 3, 4, 5};

    int *newArr = invertArray(myArray, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << *(newArr + i) << " ";
    }

    cout << " " << endl;
    delete []newArr;
    newArr = NULL;

    return 0;
}

int findMin(int array[], int length)
{
    int min = array[0];

    for (int i = 1; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

int findMax(int array[], int length)
{
    int max = array[0];

    for (int i = 1; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

void getMaxAndMin(int array[], int length, int *max, int *min)
{
    for (int i = 1; i < length; i++)
    {
        if (array[i] < *min)
        {
            *min = array[i];
        }

        if (array[i] > *max)
        {
            *max = array[i];
        }
    }
}

char *findChar(char name[], char letterToSearch)
{
    char *letter = name;

    // Every char array in c++ is ended with "\0" which means is the end of the string.
    while (*letter != '\0' && *letter != letterToSearch)
    {
        letter++;
    }

    return letter;
}

char *fooFunction()
{
    // Since this variables only exist within the function, the memory allocated by them can only be accessed until any other
    // function is executed. Which means that after it's execution, the memory allocated can be easily used by another program or
    // whatever.
    char k = '&';
    char *kptr = &k;

    return kptr;
}

void gooFuntion()
{
    cout << "goo function called " << endl;
}

char *fooFunction2()
{
    // Way 1:
    // char k = '&';
    // char *kptr = new char; // now we allocate memory dynamically
    // *kptr = k;

    // Way 2:
    char *kptr = new char;
    *kptr = '7';
    return kptr;
}

int *invertArray(int array[], int size) /*Pending to correct*/
{
    int *newArray = new int[size];

    int k = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        newArray[k] = array[i];
        k++;
    }

    return newArray;
}
#include <iostream>
using namespace std;

int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    cout << "Array address: " << array << endl;
    cout << "Array address2: " << &array[0] << endl;

    cout << "Array third element: " << array[2] << endl;
    cout << "Array third element2: " << *(array + 2) << endl;

    int luckyNumbers[5];

    for(int i = 0; i < 5; i++)
    {
        cout << "Enter number: ";
        cin >> luckyNumbers[i];
    }

    for(int i = 0; i < 5; i++)
    {
        cout << *(luckyNumbers + i) << " ";
    }

    cout << " " << endl;
    return 0;
}

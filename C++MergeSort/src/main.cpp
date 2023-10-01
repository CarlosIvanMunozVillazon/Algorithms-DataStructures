#include <iostream>
using namespace std;

void printNumber(int *printNumber);

int main ()
{

    int variable1 = 23;
    int *myPointer = &variable1;

    cout << "Var 1 value: " << variable1 << endl;
    cout << "Var 1 address: " << myPointer << endl;
    cout << "Var 1 through pointer: " << *myPointer << endl;
    cout << "Var 1 location of the pointer: " << &myPointer << endl; 

    // "*" star operator, allows pointer declaration and access to the value of the variable pointed by the pointer.
    // "&" ampersand operator, allows address extraction of a variable.

    printNumber(myPointer);
    printNumber(&variable1);

    return 0;
}

void printNumber(int *printNumber)
{
    // The parameter of this function is a pointer, therefore we have to parse it a pointer.
    // But we also can also parse the address of a variable using the "&" operator.
    cout << "Print number with pointer parameter called: " << *printNumber << endl;
}
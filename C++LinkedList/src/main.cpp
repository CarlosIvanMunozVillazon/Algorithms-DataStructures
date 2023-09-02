#include <iostream>
#include "classes/SLNode.cpp"
using namespace std;

int &fk(int a[], int i);
int main()
{
    // Singly linked list testing.
    cout << "My first linked list in cpp." << endl;

    // Creation of a node
    SLNode *head = new SLNode(4, NULL); // head holds the address of the first node
    cout << head << endl;
    cout << head->getNext() << endl; // prints the address of the next node

    int array[4] = {1, 2, 3, 4};
    cout << fk(array, 2) << endl;
    int n = fk(array, 2);

    cout << "  " << endl;
    cout << n << endl;
    cout << &n << endl;
    cout << &array[2] << endl;
    return 0;
}

int &fk(int a[], int i)
{
    return a[i];
}
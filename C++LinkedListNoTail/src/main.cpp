#include <iostream>
#include "classes/LinkedList.cpp"
using namespace std;

int main()
{

    cout << "Simple linked list implementation: " << endl;
    cout << " " << endl;

    LinkedList myList;
    myList.pushFront(8);
    myList.pushBack(12);
    myList.pushFront(1);

    myList.printList();

    myList.popBack();
    myList.printList();

    cout << myList.isEmpty() << endl;

    myList.popFront();
    myList.popFront();
    
    myList.printList();

    myList.popFront();

    myList.printList();

    return 0;
}
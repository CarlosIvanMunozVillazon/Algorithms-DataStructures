#include <iostream>
#include "classes/DoublyLinkedList.cpp"
using namespace std;

int main()
{
    cout << "Doubly linked list implementation." << endl;

    DLList myList;

    cout << myList.isEmpty() << endl;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.printList();

    myList.pushFront(4);
    myList.pushFront(5);
    myList.pushFront(6);

    myList.printList();

    cout << myList.popFront() << endl;
    cout << myList.popBack() << endl;

    myList.printList();

    cout << myList.isEmpty() << endl;

    cout << myList.belongsToList(8) << endl;
    cout << myList.belongsToList(5) << endl;

    cout << myList.deleteNode(4) << endl;
    myList.printList();

    cout << myList.deleteNode(1) << endl;
    myList.printList();

    return 0;
}
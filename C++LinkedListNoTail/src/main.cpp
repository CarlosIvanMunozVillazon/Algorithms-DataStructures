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

    cout << "" << endl;
    cout << "Testing with another list:" << endl;

    LinkedList myList2;

    myList2.pushBack(8);
    myList2.pushBack(4);
    myList2.pushBack(5);
    myList2.pushBack(6);
    myList2.pushBack(78);

    myList2.pushFront(77);
    myList2.pushFront(19);
    myList2.pushFront(41);

    cout << "77 belongs to the list?: " << myList2.belongsToList(77) << endl;
    cout << "99 belongs to the list?: " << myList2.belongsToList(99) << endl;

    myList2.printList();

    myList2.deleteNode(4);
    myList2.printList();

    myList2.deleteNode(17);
    myList2.printList();

    myList2.deleteNode(41);
    myList2.printList();

    myList2.deleteNode(78);
    myList2.printList();
    
    return 0;
}
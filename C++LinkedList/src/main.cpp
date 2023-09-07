#include <iostream>
#include "classes/SLList.cpp"
using namespace std;

int main()
{
    // Singly linked list testing.
    cout << "My first linked list in cpp." << endl;

    SLList myList;
    cout << "Linked list created" << endl;
    myList.pushFront(4);
    myList.pushBack(5);
    myList.pushBack(9);
    myList.pushBack(45);

    myList.printList();
    
    myList.deleteNode(13);
    myList.printList();
    
    //myList.deleteNode(8);

    // Creation of a node
    // SLNode *head = new SLNode(4, NULL); // head holds the address of the first node
    // cout << head << endl; // prints the adress of the current node
    // cout << head->getNext() << endl; // prints the address of the next node

    // head->next = new SLNode(8, NULL); // code if my null class didn't had encapsulated things ajaj.

    // we could continue adding nodes like this:
    // head->next->next = new SLNode(3, NULL); // this is a cumbersome notation, "cumbersome" -> engorroso

    // "diminished" -> disminuido
    return 0;
}

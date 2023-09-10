#include <iostream>
using namespace std;

class Node
{
private:
    // private stuff
protected:
    // protected stuff
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(int data = -1, Node *next = 0) // the datatype of the second parameter must be a pointer.
    {
        this->data = data,
        this->next = next;
    }

    ~Node()
    {
        if (this->next != 0) // the pointers to the next nodes should be pointed to 0 for avoiding memory leaks.
        {
            this->next = 0;
        }
    }
};

class LinkedList
{
private:
    // By making the head private, we ensure our data integrity.
    Node *head;

protected:
    // protected stuff
public:
    LinkedList()
    {
        this->head = NULL;
    }

    ~LinkedList()
    {
        Node *ref = head;

        while (ref != NULL)
        {
            ref = ref->next; // move reference to the next node
            delete head;     // delete the current head
            head = ref;      // update the head for repeating the process
        }

        ref = NULL;
        head = NULL;
    }

    // Methods to implement:
    // 1. isEmpty *
    // 2. pushBack *
    // 3. pushFront *
    // 4. popFront *
    // 5. popBack 
    // 6. deleteNode
    // 7. belongsToList
    // 8. printList *

    bool isEmpty()
    {
        return head == NULL;
    }

    void printList()
    {
        Node *ref = head;
        while (ref->next != NULL)
        {
            cout << ref->data << "--> " << endl;
            ref = ref->next;
        }
        cout << ref->data << endl;
        ref = NULL;
    }

    void pushFront(int data)
    {
        // just point the the head to a new allocated node, and the new allocated node point to the previous value of the head
        head = new Node(data, head);
    }

    void pushBack(int data)
    {
        Node *ref = head;

        while (ref->next != NULL)
        {
            ref = ref->next;
        }

        ref->next = new Node(data, NULL);
        ref = NULL;
    }

    int popFront()
    {
        int deletedElement = -1;
        if (head != NULL)
        {
            Node *ref = head; // point to the head
            deletedElement = head->data; // extract the data before deleting it
            ref = ref->next; // move the reference to the next node
            delete head; // delete the content of the current head
            head = ref; // move the head to the reference
            ref = NULL; // make the reference node point to null for avoiding memory leaks
        }

        return deletedElement;
    }
};
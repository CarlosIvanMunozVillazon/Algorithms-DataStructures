#include <iostream>
using namespace std;

class Node
{
private:
    //
protected:
    //
public:
    // Data made public isn't an issue because we make our head and tail private.
    Node *prev;
    int data;
    Node *next;

    // We need two constructors, 1 for default allocation of a new node, 2 for the allocation of new nodes with info.
    // Default constructor
    Node()
    {
        this->prev = NULL;
        this->data = -1;
        this->next = NULL;
    }

    // Standard constructor
    Node(Node *nextNode = NULL, int newData = -1, Node *previousNode = NULL)
    {
        this->next = nextNode;
        this->data = newData;
        this->prev = previousNode;
    }

    ~Node()
    {
        // Destructors deallocate memory used by instances of our objects, here the memory used by the "data" variable is deleted,
        // we just have to make sure our pointers are pointed to NULL for avoiding potential memory leaks.
        if (this->prev != NULL)
        {
            this->prev = NULL;
        }

        if (this->next != NULL)
        {
            this->next = NULL;
        }
    }
};

class DLList
{
private:
    // Head & tail are here for preserving data integrity.
    Node *head;
    Node *tail;

protected:
    //
public:
    // In the base constructor we must initialize our pointers to null.
    DLList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    // Within our destructor we must deallocate all the nodes used by our List.
    ~DLList()
    {
        // Point the ref to the node next to the head.
        Node *ref = head->next;

        while (ref != NULL)
        {
            delete head;     // Delete the head.
            head = ref;      // Move the head to the next node.
            ref = ref->next; // Move the reference to the next node.
        }

        // Point the used pointers to null for avoiding memory leaks.
        head = NULL;
        ref = NULL;
    }

    // Methods to implement:
    // 1. isEmpty *
    // 2. pushBack *
    // 3. pushFront *
    // 4. popFront *
    // 5. popBack *
    // 6. deleteNode *
    // 7. belongsToList *
    // 8. printList *

    bool isEmpty()
    {
        return this->head == NULL;
    }

    void pushBack(int newData)
    {
        if (this->tail == NULL)
        {
            this->tail = new Node(NULL, newData, NULL); // Allocate a new tail.
            this->head = this->tail;
        }
        else
        {
            this->tail->next = new Node(NULL, newData, this->tail);
            this->tail = this->tail->next; // Move the tail.
        }
    }

    void pushFront(int newData)
    {

        if (this->head == NULL)
        {
            this->head = new Node(NULL, newData, NULL); // Allocate a new head.
            this->tail = this->head;
        }
        else
        {
            this->head->prev = new Node(this->head, newData, NULL);
            this->head = this->head->prev; // Move the head.
        }
    }

    int popFront()
    {
        int deletedElement = -1;

        if (head != NULL)
        {
            Node *temporal = head;
            deletedElement = temporal->data;
            head = head->next;
            head->prev = NULL;
            delete temporal;
            temporal = NULL;
        }
        else
        {
            cout << "No data deleted." << endl;
        }

        return deletedElement;
    }

    int popBack()
    {
        int deletedElement = -1;

        if (tail != NULL)
        {
            Node *temporal = tail;
            deletedElement = temporal->data;
            tail = tail->prev;
            tail->next = NULL;
            delete temporal;
            temporal = NULL;
        }
        else
        {
            cout << "No data deleted." << endl;
        }
        return deletedElement;
    }

    int deleteNode(int deleteData)
    {
        int deletedElement = -1;

        if (deleteData == head->data)
        {
            deletedElement = head->data;
            popFront();
        }
        else if (tail->data == deleteData)
        {
            deletedElement = tail->data;
            popBack();
        }
        else
        {
            Node *ref = head->next;

            while (ref != tail && ref->data != deleteData)
            {
                ref = ref->next;
            }

            if (ref->data == deleteData)
            {
                ref->prev->next = ref->next;
                ref->next->prev = ref->prev;
                deletedElement = ref->data;
                delete ref;
                ref = NULL;
            }
            else
            {
                cout << "No data deleted." << endl;
            }
        }

        return deletedElement;
    }

    bool belongsToList(int findData)
    {
        bool notInList = true;
        Node *ref = head;

        while (ref != NULL && notInList)
        {
            notInList = ref->data != findData;
            ref = ref->next;
        }

        return !notInList;
    }

    void printList()
    {
        Node *ref = head;
        while (ref->next != NULL)
        {
            cout << ref->data << "-->";
            ref = ref->next;
        }

        cout << ref->data << endl;
        ref = NULL;
    }
};
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
    Node ()
    {
        this->prev = NULL;
        this->data = -1;
        this->next = NULL;
    }

    // Standard constructor
    Node(Node *nextNode = NULL, int newData = -1, Node *previousNode = NULL)
    {
        this->prev = nextNode;
        this->data = newData;
        this->next = previousNode;
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
    //
};
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

    Node ()
    {
        this->next = NULL;
    }

    Node (int data = -1, Node *next = 0) // the datatype of the second parameter must be a pointer.
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
    // private stuff
protected:
    // protected stuff
public:
    // public stuff
};
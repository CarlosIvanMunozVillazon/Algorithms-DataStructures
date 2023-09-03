#include <iostream>
using namespace std;

class SLNode
{

private:
    // Meanwhile i will leave the data of the node public
protected:
    // Inheritance stuff here
public:
    int data;
    SLNode *next;
    // Default constructor
    SLNode()
    {
        this->next = NULL; // point the pointer to a null value for avoiding memory leaks
    }
    // Regular constructor
    SLNode(int info = -1, SLNode *nxt = NULL) // also covers the case when only the data but not the next node is specified
    {
        this->data = info;
        this->next = nxt;
    }

    // Destructor
    ~SLNode()
    {
        if (this->next != 0)
        {
            this->next = 0; // not all the memory is deallocated, therefore we have to point the pointer to a null value
        }
    }
};

class SLList
{
private:
    // The fact that our head and tail are private while the "SLNode class" has its members public preserves the integrity of our
    // data within the list, keeping the middle elements hidden, because the access to the address of the head & tail are private
    SLNode *head;
    SLNode *tail;

protected:
    //
public:
    SLList() // List is initalized pointing to null
    {
        this->head = NULL;
        this->tail = NULL;
    }

    // SLList(SLNode *hed = 0, SLNode *tail = 0)
    // {
    //     // some things should be done here
    //     this->head = hed;
    //     this->tail = tail;
    // }

    ~SLList()
    {
        SLNode *ref = head;
        while (head != NULL) // we have to deallocate all the memory when the list gets out of scope
        {
            ref = ref->next;
            delete head;
            head = ref;
        }
        delete ref;
        ref = NULL;
        head = NULL;
    }

    int isEmpty()
    {
        return head == 0;
    }

    void pushFront(int newData)
    {
        // Point the head to the new node.
        head = new SLNode(newData, head); // We pass the head to be the "next" of our new node.

        if (tail == 0) // If we had no nodes, the tail and the head should point to the recently added node.
        {
            tail = head;
        }
    }

    void pushBack(int newData)
    {
        if (tail == 0)
        {
            tail = new SLNode(newData, NULL);
            head = tail;
        }
        else
        {
            // Point the tail to the new node.
            tail->next = new SLNode(newData, NULL); // The next of the new node should be null.
            tail = tail->next;
        }
    }

    int popFront()
    {
        // Get the element we will delete.
        int deletedElement = head->data; // If the head is null, then i think this will get a default value -1.

        // Save the address of the current head we want to delete.
        SLNode *temporal = head;

        // Head & tail are equal is because they are null or the list just has one element.
        if (head == tail)
        {
            // We make head an tail pointers point to null.
            head = NULL;
            tail = NULL;
        }
        else // in other case we move the head pointer to the next element in the list.
        {
            head = head->next;
        }

        delete temporal;       // we deallocate the memory occupied by the previous head element.
        temporal = NULL;       // for avoiding potential memory leaks we point the pointer to null.
        return deletedElement; // the deleted element info is returned
    }

    int popBack()
    {
        int deletedElement = tail->data;
        SLNode *temporal = tail;

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            SLNode *ref = head;
            while (ref->next != tail)
            {
                ref = ref->next;
            }

            tail = ref;
            tail->next = NULL;
            ref = NULL;
            delete ref;
        }

        delete temporal;
        temporal = NULL;
        return deletedElement;
    }

    void deleteNode(int data)
    {
    }

    bool belongsToList(int data)
    {
        return false;
    }

    void printList()
    {
        SLNode *ref = head;

        while (ref->next != NULL)
        {
            cout << ref->data << " --> ";
            ref = ref->next;
        }

        cout << tail->data << endl;
    }
};
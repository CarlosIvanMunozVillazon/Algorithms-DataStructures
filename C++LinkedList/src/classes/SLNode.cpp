#include <iostream>
using namespace std;

class SLNode
{

private:
    int data;
    SLNode *next;

protected:
    // Inheritance stuff here
public:
    // Default constructor
    SLNode()
    {
        this->next = 0; // point the pointer to a null value for avoiding memory leaks
    }
    // Regular constructor
    SLNode(int info, SLNode *nxt) // also covers the case when only the data but not the next node is specified
    {
        this->data = info;
        this->next = nxt;
    }
    SLNode* getNext(){
        return this->next;
    }
    int getData(){
        return this->data;
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
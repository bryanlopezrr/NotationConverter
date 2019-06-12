#include "DLinkedList.hpp"

//IE: This particular implemntation of a deque is using a Doubly Linked List under the hood
class LDeque {
    /*     A deque consists of: 
            |------------------------------------------------------|
            |<-front* | node | node | node | node | node... *rear->|
            |------------------------------------------------------|
            In which you can add/remove items both from the front and the back
    */
private:
    DLinkedList D;
    int n; //used to keep track of size   
public:
    //Constructor/Destructor for deque
    LDeque();
    ~LDeque();

    //Reference functions to the front and back
    const string& front() const throw();
    const string& back() const throw();

    //Operations to insert, remove and check if deque is empty for the deque
    void insertFront(const string& e);
    void insertBack(const string& e);
    void removeFront() throw();
    void removeBack() throw();
    bool empty() const;

    //Size of the deque at a point
    int size() const;
};


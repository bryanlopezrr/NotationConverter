#include "DNode.hpp"

//IE: Remember that Elem in this case is a typedef of string initialized in Node.hpp
class DLinkedList : public DNode {
    private:
        //Sentinel nodes
        DNode* header;
        DNode* trailer;
    protected:
        //Functions used 'under the hood' by addFront, addBack, removeFront, removeBack
        void add(DNode* v, const Elem& e);
        void remove(DNode* v);
    public:
        //Constructor and Destructor for the class objects
        DLinkedList();
        ~DLinkedList();
    
        //Reference functions to the front and back
        const Elem& front() const;
        const Elem& back() const;

        //Operations to add, remove and check if list is empty for the linked list
        void addFront(const Elem& e);
        void addBack(const Elem& e);
        void removeFront();
        void removeBack();
        bool empty() const;
};


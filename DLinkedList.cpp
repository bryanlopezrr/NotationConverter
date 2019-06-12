#include "DLinkedList.hpp"

/*FYE: Functions were provided by the lecture notes given by Dr. Oropallo on this particular
      implementation of a doubly linked list data structure*/

      
//CONSTRUCTOR/DESTRUCTOR
//----------------------------------------------------------------------------------------->
DLinkedList::DLinkedList() {
    /* This constructor will be initializing and setting up the sentinel values
       that will help me know where the beginning and end of the list are.
    */
    //    |---| ---> |---|
    //    | H |      | T |
    //    |---| <--- |---|
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList(){
    /* This destructor checks if the list is empty or not. In the latter it will remove the
       header->next node and will continue to do so unitl the list is empty
    */
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

//CHECK FOR EMPTY LIST
//----------------------------------------------------------------------------------------->
bool DLinkedList::empty() const {
    //             |---| ---> |---|
    //             | H |      | T |
    //             |---| <--- |---|

    // This function checks if ^ indeed is empty or not
    return (header->next == trailer);
}

//REFERENCE FUNCTIONS TO POINT TO THE FRONT/BACK
//----------------------------------------------------------------------------------------->
const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

//ADD TO LIST FUNCTIONS
//----------------------------------------------------------------------------------------->
void DLinkedList::add(DNode* v, const Elem& e) {
    /* This function will add a node into the list and set the pointers appropriately to 
       traverse through the list afterwards
    */
    DNode* u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem &e) {
    add(header->next, e);
}

void DLinkedList::addBack(const Elem &e) {
    add(trailer, e);
}

//REMOVE FROM LIST FUNCTIONS
//----------------------------------------------------------------------------------------->
void DLinkedList::remove(DNode* v){
    /* This function will remove the node passed to it and will move the pointers to make sure
       the links are set up properly
    */
    if (!empty()){
        DNode* u = v->prev; 
        DNode* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}

void DLinkedList::removeFront(){
    remove(header->next);
}

void DLinkedList::removeBack(){
    remove(trailer->prev);
}




//----------------------------------------------------------------------------------------->
//END OF FUNCTIONS FOR THIS FILE


